#include "AnonymReqArg.h"

namespace simpleCLI {
    AnonymReqArg::AnonymReqArg() {
        reset();
    }

    AnonymReqArg::~AnonymReqArg() {
        if (value) delete value;

        if (next) delete next;
    }

    bool AnonymReqArg::equals(const char* name) {
        return strlen(name) == 0;
    }

    bool AnonymReqArg::equals(String name) {
        return name.length() == 0;
    }

    void AnonymReqArg::setValue(String value) {
        if (value.length() > 0) {
            if (AnonymReqArg::value) delete AnonymReqArg::value;

            int strLen = value.length() + 1;
            AnonymReqArg::value = new char[strLen];
            value.toCharArray(AnonymReqArg::value, strLen);

            set = true;
        }
    }

    void AnonymReqArg::reset() {
        if (value) {
            delete value;
            value = NULL;
        }

        Arg::reset();
    }

    String AnonymReqArg::getValue() {
        return value ? String(value) : String();
    }

    bool AnonymReqArg::isRequired() {
        return true;
    }

    String AnonymReqArg::toString() {
        return "<value>";
    }
}