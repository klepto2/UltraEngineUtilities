#pragma once
#include "UltraEngine.h"
#include "../../external/includes/shaderc.hpp"

#include <unordered_set>
#include <cassert>
#include <fstream>
#include <ios>

using namespace UltraEngine;
using namespace shaderc;

namespace UltraEngine::Utilities::Shader::Internal
{
	class string_piece {
	public:
		typedef const char* iterator;
		static const size_t npos = -1;

		string_piece() {}

		string_piece(const char* begin, const char* end) : begin_(begin), end_(end) {
			assert((begin == nullptr) == (end == nullptr) &&
				"either both begin and end must be nullptr or neither must be");
		}

		string_piece(const char* string) : begin_(string), end_(string) {
			if (string) {
				end_ += strlen(string);
			}
		}

		string_piece(const string& str) {
			if (!str.empty()) {
				begin_ = &(str.front());
				end_ = &(str.back()) + 1;
			}
		}

		string_piece(const string_piece& other) {
			begin_ = other.begin_;
			end_ = other.end_;
		}

		string_piece& operator=(const string_piece& other) = default;

		// Clears the string_piece removing any reference to the original string.
		void clear() {
			begin_ = nullptr;
			end_ = nullptr;
		}

		// Returns a pointer to the data contained in the underlying string.
		// If there is no underlying string, returns a nullptr.
		const char* data() const { return begin_; }

		// Returns an std::string copy of the internal data.
		string str() const { return string(begin_, end_); }

		// Returns a string_piece that points to a substring in the original string.
		string_piece substr(size_t pos, size_t len = npos) const {
			assert(len == npos || pos + len <= size());
			return string_piece(begin_ + pos, len == npos ? end_ : begin_ + pos + len);
		}

		// Takes any function object predicate that takes a char and returns a
		// boolean.
		// Returns the index of the first element that does not return true for the
		// predicate.
		// Returns string_piece::npos if all elements match.
		template <typename T>
		size_t find_first_not_matching(T callee) {
			for (auto it = begin_; it != end_; ++it) {
				if (!callee(*it)) {
					return it - begin_;
				}
			}
			return npos;
		}

		// Returns the index of the first character that does not match any character
		// in the input string_piece.
		// The search only includes characters at or after position pos.
		// Returns string_piece::npos if all match.
		size_t find_first_not_of(const string_piece& to_search,
			size_t pos = 0) const {
			if (pos >= size()) {
				return npos;
			}
			for (auto it = begin_ + pos; it != end_; ++it) {
				if (to_search.find_first_of(*it) == npos) {
					return it - begin_;
				}
			}
			return npos;
		}

		// Returns find_first_not_of(str, pos) where str is a string_piece
		// containing only to_search.
		size_t find_first_not_of(char to_search, size_t pos = 0) const {
			return find_first_not_of(string_piece(&to_search, &to_search + 1), pos);
		}

		// Returns the index of the first character that matches any character in the
		// input string_piece.
		// The search only includes characters at or after position pos.
		// Returns string_piece::npos if there is no match.
		size_t find_first_of(const string_piece& to_search, size_t pos = 0) const {
			if (pos >= size()) {
				return npos;
			}
			for (auto it = begin_ + pos; it != end_; ++it) {
				for (char c : to_search) {
					if (c == *it) {
						return it - begin_;
					}
				}
			}
			return npos;
		}

		// Returns find_first_of(str, pos) where str is a string_piece
		// containing only to_search.
		size_t find_first_of(char to_search, size_t pos = 0) const {
			return find_first_of(string_piece(&to_search, &to_search + 1), pos);
		}

		// Returns the index of the last character that matches any character in the
		// input string_piece.
		// The search only includes characters at or before position pos.
		// Returns string_piece::npos if there is no match.
		size_t find_last_of(const string_piece& to_search, size_t pos = npos) const {
			if (empty()) return npos;
			if (pos >= size()) {
				pos = size();
			}
			auto it = begin_ + pos + 1;
			do {
				--it;
				if (to_search.find_first_of(*it) != npos) {
					return it - begin_;
				}
			} while (it != begin_);
			return npos;
		}

		// Returns find_last_of(str, pos) where str is a string_piece
		// containing only to_search.
		size_t find_last_of(char to_search, size_t pos = npos) const {
			return find_last_of(string_piece(&to_search, &to_search + 1), pos);
		}

		// Returns the index of the last character that does not match any character
		// in the input string_piece.
		// The search only includes characters at or before position pos.
		// Returns string_piece::npos if there is no match.
		size_t find_last_not_of(const string_piece& to_search,
			size_t pos = npos) const {
			if (empty()) return npos;
			if (pos >= size()) {
				pos = size();
			}
			auto it = begin_ + pos + 1;
			do {
				--it;
				if (to_search.find_first_of(*it) == npos) {
					return it - begin_;
				}
			} while (it != begin_);
			return npos;
		}

		// Returns find_last_not_of(str, pos) where str is a string_piece
		// containing only to_search.
		size_t find_last_not_of(char to_search, size_t pos = 0) const {
			return find_last_not_of(string_piece(&to_search, &to_search + 1), pos);
		}

		// Continuously removes characters appearing in chars_to_strip from the left.
		string_piece lstrip(const string_piece& chars_to_strip) const {
			iterator begin = begin_;
			for (; begin < end_; ++begin)
				if (chars_to_strip.find_first_of(*begin) == npos) break;
			if (begin >= end_) return string_piece();
			return string_piece(begin, end_);
		}

		// Continuously removes characters appearing in chars_to_strip from the right.
		string_piece rstrip(const string_piece& chars_to_strip) const {
			iterator end = end_;
			for (; begin_ < end; --end)
				if (chars_to_strip.find_first_of(*(end - 1)) == npos) break;
			if (begin_ >= end) return string_piece();
			return string_piece(begin_, end);
		}

		// Continuously removes characters appearing in chars_to_strip from both
		// sides.
		string_piece strip(const string_piece& chars_to_strip) const {
			return lstrip(chars_to_strip).rstrip(chars_to_strip);
		}

		string_piece strip_whitespace() const { return strip(" \t\n\r\f\v"); }

		// Returns the character at index i in the string_piece.
		const char& operator[](size_t i) const { return *(begin_ + i); }

		// Standard comparison operator.
		bool operator==(const string_piece& other) const {
			// Either end_ and _begin_ are nullptr or neither of them are.
			assert(((end_ == nullptr) == (begin_ == nullptr)));
			assert(((other.end_ == nullptr) == (other.begin_ == nullptr)));
			if (size() != other.size()) {
				return false;
			}
			return (memcmp(begin_, other.begin_, end_ - begin_) == 0);
		}

		bool operator!=(const string_piece& other) const {
			return !operator==(other);
		}

		// Returns an iterator to the first element.
		iterator begin() const { return begin_; }

		// Returns an iterator to one past the last element.
		iterator end() const { return end_; }

		const char& front() const {
			assert(!empty());
			return *begin_;
		}

		const char& back() const {
			assert(!empty());
			return *(end_ - 1);
		}

		// Returns true is this string_piece starts with the same
		// characters as other.
		bool starts_with(const string_piece& other) const {
			const char* iter = begin_;
			const char* other_iter = other.begin();
			while (iter != end_ && other_iter != other.end()) {
				if (*iter++ != *other_iter++) {
					return false;
				}
			}
			return other_iter == other.end();
		}

		// Returns the index of the start of the first substring that matches
		// the input string_piece.
		// The search only includes substrings starting at or after position pos.
		// Returns npos if the string cannot be found.
		size_t find(const string_piece& substr, size_t pos = 0) const {
			if (empty()) return npos;
			if (pos >= size()) return npos;
			if (substr.empty()) return 0;
			for (auto it = begin_ + pos;
				end() - it >= static_cast<decltype(end() - it)>(substr.size()); ++it) {
				if (string_piece(it, end()).starts_with(substr)) return it - begin_;
			}
			return npos;
		}

		// Returns the index of the start of the first character that matches
		// the input character.
		// The search only includes substrings starting at or after position pos.
		// Returns npos if the character cannot be found.
		size_t find(char character, size_t pos = 0) const {
			return find_first_of(character, pos);
		}

		// Returns true if the string_piece is empty.
		bool empty() const { return begin_ == end_; }

		// Returns the number of characters in the string_piece.
		size_t size() const { return end_ - begin_; }

		// Returns a vector of string_pieces representing delimiter delimited
		// fields found. If the keep_delimiter parameter is true, then each
		// delimiter character is kept with the string to its left.
		vector<string_piece> get_fields(char delimiter,
			bool keep_delimiter = false) const {
			vector<string_piece> fields;
			size_t first = 0;
			size_t field_break = find_first_of(delimiter);
			while (field_break != npos) {
				fields.push_back(substr(first, field_break - first + keep_delimiter));
				first = field_break + 1;
				field_break = find_first_of(delimiter, first);
			}
			if (size() - first > 0) {
				fields.push_back(substr(first, size() - first));
			}
			return fields;
		}

		friend std::ostream& operator<<(std::ostream& os, const string_piece& piece);

	private:
		// It is expected that begin_ and end_ will both be null or
		// they will both point to valid pieces of memory, but it is invalid
		// to have one of them being nullptr and the other not.
		string_piece::iterator begin_ = nullptr;
		string_piece::iterator end_ = nullptr;
	};

	inline std::ostream& operator<<(std::ostream& os, const string_piece& piece) {
		// Either end_ and _begin_ are nullptr or neither of them are.
		assert(((piece.end_ == nullptr) == (piece.begin_ == nullptr)));
		if (piece.end_ != piece.begin_) {
			os.write(piece.begin_, piece.end_ - piece.begin_);
		}
		return os;
	}

	inline bool operator==(const char* first, const string_piece second) {
		return second == first;
	}

	inline bool operator!=(const char* first, const string_piece second) {
		return !operator==(first, second);
	}
}
	namespace std {
		template <>
		struct hash< UltraEngine::Utilities::Shader::Internal::string_piece> {
			size_t operator()(const  UltraEngine::Utilities::Shader::Internal::string_piece& piece) const {
				// djb2 algorithm.
				size_t hash = 5381;
				for (char c : piece) {
					hash = ((hash << 5) + hash) + c;
				}
				return hash;
			}
		};
	}
namespace UltraEngine::Utilities::Shader::Internal
{
	shaderc_include_result* MakeErrorIncludeResult(const char* message) {
		return new shaderc_include_result{ "", 0, message, strlen(message) };
	}

	string MaybeSlash(const string_piece& path) {
		return (path.empty() || path.back() == '/') ? "" : "/";
	}


	class ShaderFileCollector : public shaderc::CompileOptions::IncluderInterface {
		
	private:
		string basePath = "";
		std::vector<std::string> search_path_;
		vector<WString>& Includes;

		std::string FindReadableFilepath(
			const std::string& filename) const {
			assert(!filename.empty());
			static const auto for_reading = std::ios_base::in;
			std::filebuf opener;
			for (const auto& prefix : search_path_) {
				const std::string prefixed_filename =
					prefix + MaybeSlash(prefix) + filename;
				if (opener.open(prefixed_filename, for_reading)) return prefixed_filename;
			}
			return "";
		}

		std::string FindRelativeReadableFilepath(
			const std::string& requesting_file, const std::string& filename) const {
			assert(!filename.empty());

			string_piece dir_name(requesting_file);

			size_t last_slash = requesting_file.find_last_of("/\\");
			if (last_slash != std::string::npos) {
				dir_name = string_piece(requesting_file.c_str(),
					requesting_file.c_str() + last_slash);
			}

			if (dir_name.size() == requesting_file.size()) {
				dir_name.clear();
			}

			static const auto for_reading = std::ios_base::in;
			std::filebuf opener;
			const std::string relative_filename =
				dir_name.str() + MaybeSlash(dir_name) + filename;
			if (opener.open(relative_filename, for_reading)) return relative_filename;

			return FindReadableFilepath(filename);
		}
	public:
		ShaderFileCollector(string path, vector<WString>& includes) : basePath(path), Includes(includes)
		{
			search_path_.push_back(path);
			auto dirs = LoadDir(CurrentDir().ToString() + "/Shaders", 2);
			for (auto d : dirs)
				search_path_.push_back(CurrentDir().ToString() + "/Shaders/" + d.ToString());
		}


		// Resolves a requested source file of a given type from a requesting
		// source into a shaderc_include_result whose contents will remain valid
		// until it's released.
		shaderc_include_result* GetInclude(const char* requested_source,
			shaderc_include_type type,
			const char* requesting_source,
			size_t include_depth) override
		{
			const string name = string(requested_source);
			const string req_name = string(requesting_source);
			string path = ExtractDir(name);

			if (path.length() == 0)
				path = basePath;

			const std::string full_path =
				(type == shaderc_include_type_relative)
				? FindRelativeReadableFilepath(requesting_source,
					requested_source)
				: FindReadableFilepath(requested_source);

			if (full_path.empty())
				return MakeErrorIncludeResult("Cannot find or open include file.");

			auto includePath = FixPath(RealPath(WString(full_path)));

			if (find(Includes.begin(), Includes.end(), includePath) == Includes.end())
			{
				Includes.push_back(includePath);
			}

			const string contents = LoadString(full_path);

			auto container = new std::array<std::string, 2>;
			(*container)[0] = name;
			(*container)[1] = contents;

			auto data = new shaderc_include_result;

			data->user_data = container;

			data->source_name = (*container)[0].data();
			data->source_name_length = (*container)[0].size();

			data->content = (*container)[1].data();
			data->content_length = (*container)[1].size();

			return data;
		}
		// Releases an include result.
		void ReleaseInclude(shaderc_include_result* include_result) override
		{
			delete static_cast<std::array<std::string, 2>*>(include_result->user_data);
			delete include_result;
		}

		// Returns a reference to the member storing the set of included files.
		const std::unordered_set<std::string>& file_path_trace() const {
			return included_files_;
		}


	private:
		// The full path and content of a source file.
		struct FileInfo {
			const std::string full_path;
			std::vector<char> contents;
		};

		// The set of full paths of included files.
		std::unordered_set<std::string> included_files_;
	};
}
