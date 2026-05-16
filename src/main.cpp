#include <crc_form.hpp>
#include <nana/gui.hpp>

int main(int argc, const char** argv)
{
    crc_form form { 620, 250 };
    form.print_form();
    form.caption("Generator sumy kontrolnej Modbus CRC");
    nana::exec();

    return 0;
}
