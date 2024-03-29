// Copyright(c) 2015-present, Gabi Melman & spdlog contributors.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#pragma once

#include <map>

namespace spdlog {

class mdc {
public:
    static void put(const std::string &key, const std::string &value) {
        get_context()[key] = value;
    }

    static std::string get(const std::string &key) {
        auto &context = get_context();
        auto it = context.find(key);
        if (it != context.end()) {
            return it->second;
        }
        return "";
    }

    static void remove(const std::string &key) { get_context().erase(key); }

    static void clear() { get_context().clear(); }

    static std::map<std::string, std::string> &get_context() {
        static thread_local std::map<std::string, std::string> context;
        return context;
    }
};

}  // namespace spdlog
