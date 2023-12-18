// Copyright(c) 2015-present, Gabi Melman & spdlog contributors.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#pragma once

#ifndef DDS_LINK__H
#define DDS_LINK__H
#include <iostream>
#include <memory>
#include <mutex>

class dds_link_count{
    private:
       int link_count;
    public:
        dds_link_count();
        ~dds_link_count();
        void add_link_count();
        void subtract_link_count();
        int get_link_count();
};

#endif