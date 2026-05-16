/**
 * \file crc_form.cpp
 * Created by Piotr Karol 2026
 */
#include <crc_form.hpp>

#include <crc_calculator.hpp>

crc_form::crc_form(const std::uint16_t width, const std::uint16_t height) :
    form { nana::API::make_center(width, height) },
    layout(*this),
    label_crc(*this, "Wpisz liczbę w notacji heksadecymalnej:"),
    input_crc(*this),
    label_iter(*this, "Wpisz liczbę iteracji: "),
    input_iter(*this),
    crc_header(*this, "Suma kontrolna CRC: "),
    crc_result(*this),
    iter_header(*this, "Czas jednej iteracji: "),
    iter_result(*this),
    time_header(*this, "Całkowity czas: "),
    time_result(*this),
    btn_generate(*this, "Generuj")
{
    input_iter.multi_lines(false);
    btn_generate.events().click([&](const auto&)
                                { btn_generate_click(); });
    init_layout();
}

void crc_form::init_layout()
{
    layout.div(R"(
        margin=15 gap=10
            vertical
            <weight=20
                <weight=220 label_crc><input_crc>
            >
            <weight=20
                <weight=220 label_iter><input_iter>
            >
            <weight=150 vertical margin=15 gap=5
                <weight=30 horizontal gap=5 crc>
                <weight=30 horizontal gap=5 iter>
                <weight=30 horizontal gap=5 time>
            >

            <weight=40 btn_generate>
        )");

    layout["label_crc"] << label_crc;
    layout["input_crc"] << input_crc;

    layout["label_iter"] << label_iter;
    layout["input_iter"] << input_iter;

    layout["crc"] << crc_header << crc_result;
    layout["iter"] << iter_header << iter_result;
    layout["time"] << time_header << time_result;

    layout["btn_generate"] << btn_generate;
}

void crc_form::print_form()
{
    layout.collocate();
    show();
}

void crc_form::btn_generate_click()
{
    std::string msg = input_crc.text();
    try
    {
        std::stoi(msg, nullptr, 16);
        std::uint32_t  iter = std::stoull(input_iter.text());
        std::uint32_t  time{};
        crc_calculator crc_calc { msg, iter };
        crc_calc.generate_crc(msg, iter, time);
        crc_result.caption(msg);
        iter_result.caption(time_nano_to_milli(iter) + " [ms]");
        time_result.caption(time_nano_to_milli(time) + " [ms]");

    }
    catch (std::invalid_argument e)
    {
        nana::msgbox mb { "Wpisano niepoprawne dane" };
        mb.icon(nana::msgbox::icon_warning);
        mb << "Wprowadzone dane są błędne." << std::endl;
        mb.show();
    }
}

std::string crc_form::time_nano_to_milli(std::uint32_t time_nanoseconds)
{
    double milliseconds = static_cast<double>(time_nanoseconds) / 1000000.0;
    std::stringstream ss;
    ss << std::fixed << std::setprecision(6) << milliseconds;
    return ss.str();
}
