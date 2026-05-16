/**
 * \file crc_calculator.hpp
 * Created by Piotr Karol 2026
 */
#ifndef MODBUSCRC_CRC_CALCULATOR_HPP
#define MODBUSCRC_CRC_CALCULATOR_HPP
#include <cstdint>
#include <string>
#include <vector>

class crc_calculator
{
public:
    std::string&  msg;
    std::uint32_t iterations;

    explicit crc_calculator(std::string& msg, std::uint32_t iterations);
    void generate_crc(std::string& msg, std::uint32_t& iter_time, std::uint32_t& time);

private:
    std::uint16_t calculate_crc(const uint8_t* data, size_t len);

    std::vector<uint8_t> hex_to_bytes(const std::string& hex);
};

#endif // MODBUSCRC_CRC_CALCULATOR_HPP
