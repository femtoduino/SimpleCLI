#ifndef helper_functions_h
#define helper_functions_h

namespace arduino_cli {
    inline int equals(const char *str, const char *keyword) {
        if (!str || !keyword) return -3;

        int lenStr     = strlen(str);
        int lenKeyword = strlen(keyword);

        // string can't be longer than keyword (but can be smaller because of  '/' and ',')
        if (lenStr > lenKeyword) return -2;

        if (lenStr == lenKeyword) return strcmp(str, keyword) == 0 ? 0 : -1;

        int  resIndex = 0;
        int  a        = 0;
        int  b        = 0;
        bool result   = true;

        while (a < lenStr && b < lenKeyword) {
            if (keyword[b] == '/') {
                b++;
            } else if (keyword[b] == ',') {
                b++;
                a = 0;
                resIndex++;
            }

            if (tolower(str[a]) != tolower(keyword[b])) result = false;

            // fast forward to next comma
            if (((a == lenStr) && !result) || !result) {
                while (b < lenKeyword && keyword[b] != ',') b++;
                result = true;
            } else {
                a++;
                b++;
            }
        }

        // comparison correct AND string checked until the end AND keyword
        // checked
        // until the end
        if (result && (a == lenStr) &&
            ((keyword[b] == ',') || (keyword[b] == '/') ||
             (keyword[b] == '\0'))) return resIndex;
        else return -1;
    }

    inline String readTemplate(const char *_template) {
        String str = String();
        int    len = strlen(_template);
        int    i   = 0;

        while (i < len && _template[i] != '/' && _template[i] != ',') {
            str += _template[i];
            i++;
        }

        return str;
    }
}

#endif // ifndef helper_functions_h