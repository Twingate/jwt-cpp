#ifndef JWT_CPP_KAZUHO_OPTIMIZED_PICOJSON_DEFAULTS_H
#define JWT_CPP_KAZUHO_OPTIMIZED_PICOJSON_DEFAULTS_H

#include "traits.h"

namespace jwt {
	/**
	 * \brief a class to store a generic [optimized_picojson](https://github.com/kazuho/optimized_picojson) value as claim
	 *
	 * This type is the specialization of the \ref basic_claim class which
	 * uses the standard template types.
	 */
	using claim = basic_claim<traits::optimized_picojson_t>;

	/**
	 * Create a verifier using the default clock
	 * \return verifier instance
	 */
	inline verifier<default_clock, traits::optimized_picojson_t> verify() {
		return verify<default_clock, traits::optimized_picojson_t>(default_clock{});
	}

	/**
	 * Return a builder instance to create a new token
	 */
	inline builder<traits::optimized_picojson_t> create() { return builder<traits::optimized_picojson_t>(); }

#ifndef JWT_DISABLE_BASE64
	/**
	 * Decode a token
	 * \param token Token to decode
	 * \return Decoded token
	 * \throw std::invalid_argument Token is not in correct format
	 * \throw std::runtime_error Base64 decoding failed or invalid json
	 */
	inline decoded_jwt<traits::optimized_picojson_t> decode(const std::string_view& token) {
		return decoded_jwt<traits::optimized_picojson_t>(token);
	}
#endif

	/**
	 * Decode a token
	 * \tparam Decode is callabled, taking a string_type and returns a string_type.
	 * It should ensure the padding of the input and then base64url decode and
	 * return the results.
	 * \param token Token to decode
	 * \param decode The token to parse
	 * \return Decoded token
	 * \throw std::invalid_argument Token is not in correct format
	 * \throw std::runtime_error Base64 decoding failed or invalid json
	 */
	template<typename Decode>
	decoded_jwt<traits::optimized_picojson_t> decode(const std::string_view& token, Decode decode) {
		return decoded_jwt<traits::optimized_picojson_t>(token, decode);
	}

	/**
	 * Parse a jwk
	 * \param token JWK Token to parse
	 * \return Parsed JWK
	 * \throw std::runtime_error Token is not in correct format
	 */
	inline jwk<traits::optimized_picojson_t> parse_jwk(const std::string& token) {
		return jwk<traits::optimized_picojson_t>(token);
	}

	/**
	 * Parse a jwks
	 * \param token JWKs Token to parse
	 * \return Parsed JWKs
	 * \throw std::runtime_error Token is not in correct format
	 */
	inline jwks<traits::optimized_picojson_t> parse_jwks(const std::string& token) {
		return jwks<traits::optimized_picojson_t>(token);
	}
} // namespace jwt

#endif // JWT_CPP_KAZUHO_OPTIMIZED_PICOJSON_DEFAULTS_H
