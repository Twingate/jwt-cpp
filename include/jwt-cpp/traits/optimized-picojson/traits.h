#ifndef JWT_CPP_OPTIMIZED_PICOJSON_TRAITS_H
#define JWT_CPP_OPTIMIZED_PICOJSON_TRAITS_H

#ifndef OPTIMIZED_PICOJSON_USE_INT64
#define OPTIMIZED_PICOJSON_USE_INT64
#endif
#include "picojson/optimized_picojson.h"

#ifndef JWT_DISABLE_OPTIMIZED_PICOJSON
#define JWT_DISABLE_OPTIMIZED_PICOJSON
#endif
#include "jwt-cpp/jwt.h"

namespace jwt {
	namespace traits {
		struct optimized_picojson_t {
			using value_type = optimized_picojson::value;
			using object_type = optimized_picojson::object;
			using array_type = optimized_picojson::array;
			using string_type = optimized_picojson::optimized_string_t;
			using hasher = optimized_picojson::hash_optimized_string_t;
			using number_type = double;
			using integer_type = int64_t;
			using boolean_type = bool;

			static json::type get_type(const optimized_picojson::value& val) {
				using json::type;
				if (val.is<bool>()) return type::boolean;
				if (val.is<int64_t>()) return type::integer;
				if (val.is<double>()) return type::number;
				if (val.is<optimized_picojson::optimized_string_t>()) return type::string;
				if (val.is<optimized_picojson::array>()) return type::array;
				if (val.is<optimized_picojson::object>()) return type::object;

				throw std::logic_error("invalid type");
			}

			static optimized_picojson::object as_object(const optimized_picojson::value& val) {
				if (!val.is<optimized_picojson::object>()) throw std::bad_cast();
				return val.get<optimized_picojson::object>();
			}

                        static optimized_picojson::optimized_string_t as_string(const optimized_picojson::value& val) {
                            if (!val.is<optimized_picojson::optimized_string_t>()) throw std::bad_cast();
                            return val.get<optimized_picojson::optimized_string_t>();
                        }

			static optimized_picojson::array as_array(const optimized_picojson::value& val) {
				if (!val.is<optimized_picojson::array>()) throw std::bad_cast();
				return val.get<optimized_picojson::array>();
			}

			static int64_t as_int(const optimized_picojson::value& val) {
				if (!val.is<int64_t>()) throw std::bad_cast();
				return val.get<int64_t>();
			}

			static bool as_bool(const optimized_picojson::value& val) {
				if (!val.is<bool>()) throw std::bad_cast();
				return val.get<bool>();
			}

			static double as_number(const optimized_picojson::value& val) {
				if (!val.is<double>()) throw std::bad_cast();
				return val.get<double>();
			}

			static bool parse(optimized_picojson::value& val, const std::string& str) {
				return optimized_picojson::parse(val, optimized_picojson::optimized_string_t(str.c_str(), str.size(), true)).empty();
			}

			static std::string serialize(const optimized_picojson::value& val) { return val.serialize(); }
		};
	} // namespace traits
} // namespace jwt

#endif
