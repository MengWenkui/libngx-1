#include <ngx_config.h>
#include <ngx_core.h>

#include <stdio.h>

int 
main(int argc, char *argv[]) 
{
    ngx_str_t t = ngx_string("Hello, world!");

    printf("%zu - %s\n", t.len, t.data);

    return 0;
}

