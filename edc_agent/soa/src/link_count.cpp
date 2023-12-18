#include "changan/link_count.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


dds_link_count::dds_link_count()
{
    link_count = 0;
}

dds_link_count::~dds_link_count()
{

}

void dds_link_count::add_link_count()
{
	if(this->link_count<2)
	{
        (this->link_count)++;
	}
}

void dds_link_count::subtract_link_count()
{
    if(this->link_count>0)
	{
		(this->link_count)--;
	}
}

int dds_link_count::get_link_count()
{
    return this->link_count;
}