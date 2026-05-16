/**
 * \file crc_form.hpp
 * Created by Piotr Karol 2026
 */
#ifndef MODBUSCRC_CRC_FORM_HPP
#define MODBUSCRC_CRC_FORM_HPP

#include "nana/gui.hpp"
#include "nana/gui/widgets/checkbox.hpp"

#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/form.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/textbox.hpp>

class crc_form : public nana::form
{
public:
    explicit crc_form(std::uint16_t width, std::uint16_t height);
    void init_layout();
    void print_form();

private:
    nana::place       layout;
    nana::label       label_crc;
    nana::textbox     input_crc;
    nana::label       label_iter;
    nana::textbox     input_iter;
    nana::button      btn_generate;
    nana::label       crc_header;
    nana::label       crc_result;
    nana::label       iter_header;
    nana::label       iter_result;
    nana::label       time_header;
    nana::label       time_result;

    void btn_generate_click();
    std::string time_nano_to_milli(std::uint32_t time_nanoseconds);
};

#endif // MODBUSCRC_CRC_FORM_HPP
