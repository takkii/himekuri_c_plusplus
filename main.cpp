#include "all.h"

int main(void) {
    try {
        time_t now = time(nullptr);
        const tm *nowlt = localtime(&now);

        stringstream x;
        x << "R0";
        x << nowlt->tm_year - 118;
        x << ".";
        x << nowlt->tm_mon + 1;
        x << ".";
        x << nowlt->tm_mday;

        string result_r = x.str();

        stringstream y;
        y << "�ߘa";
        y << nowlt->tm_year - 118;
        y << "�N";
        y << nowlt->tm_mon + 1;
        y << "��";
        y << nowlt->tm_mday;
        y << "��";

        string result_reiwa = y.str();


        stringstream z;
        z << "20";
        z << nowlt->tm_year - 100;
        z << "�N";
        z << nowlt->tm_mon + 1;
        z << "��";
        z << nowlt->tm_mday;
        z << "��" << " : ";
        z << nowlt->tm_hour;
        z << "��";
        z << nowlt->tm_min;
        z << "��";
        z << nowlt->tm_sec;
        z << "�b";

        auto result = z.str();

        // OneYear �� 365 days.
        auto OneYear_Days = 365;

        auto redays = nowlt->tm_yday;
        auto redays_mini = OneYear_Days - redays;

        auto tim = "���ݎ���";
        auto gantan = "���N��1��1���܂ł���";
        auto aisatu = " ���ł�";
        auto number = "���߂��萔���ԍ�";
        auto week = "�j��";

        // week Sun ~ Sat
        time_t timer;
        struct tm *t_st;
        const char *wday[] = {"��", "��", "��", "��", "��", "��", "�y"};

        // Month �a����
        const char *wmonth[] = {"�r��", "�@��", "�퐶", "�K��", "�H��", "������", "����", "�t��", "����", "�_����", "����", "�t��"
        };

        time(&timer);
        t_st = localtime(&timer);

        stringstream ss;
        stringstream ssd;

        // version number
        ss << 1;
        ssd << 2;
        auto str_num = ss.str();
        auto str_dd = ssd.str();
        string comma = " : ";

        // version number comma
        auto number_comma = ".1.";

        auto himekuri = number + comma + str_num + number_comma + str_dd;

        cout << tim << comma << result << comma << wday[t_st->tm_wday] << week << comma << wmonth[t_st->tm_mon] << endl;
        cout << gantan << comma << redays_mini << aisatu << endl;
        cout << result_reiwa << comma << result_r << endl;
        cout << himekuri << endl;

        // C++ version info.
        auto cpp20 = 202002L;
        auto cpp17 = 201703L;
        auto cpp17_2 = 201709L;
        auto cpp14 = 201402L;
        auto cpp11 = 201103L;
        auto cpp98 = 199711L;

        // long type �� string type.
        string cpp_ver = to_string(__cplusplus);

        if (cpp_ver.compare(to_string(cpp20)) == 0)
            cout << "���݂� C++ : C++20" << endl;
        else if (cpp_ver.compare(to_string(cpp17)) == 0)
            cout << "���݂� C++ : C++17" << endl;
        else if (cpp_ver.compare(to_string(cpp17_2)) == 0)
            cout << "���݂� C++ : C++17" << endl;
        else if (cpp_ver.compare(to_string(cpp14)) == 0)
            cout << "���݂� C++ : C++14" << endl;
        else if (cpp_ver.compare(to_string(cpp11)) == 0)
            cout << "���݂� C++ : C++11" << endl;
        else if (cpp_ver.compare(to_string(cpp98)) == 0)
            cout << "���݂� C++ : C++98" << endl;
        else
            cout << "���݂� C++ : pre-standard C++" << endl;

    } catch (const runtime_error &e) {
        cout << "runtime_error : " << e.what() << endl;
    } catch (const exception &e) {
        cout << "some exception : " << e.what() << endl;
    }
    exit(0);
}
