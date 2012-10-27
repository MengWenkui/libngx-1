
#include <ngx_config.h>
#include <ngx_core.h>

#include <stdio.h>


void ngx_log_error_core(ngx_uint_t level, ngx_log_t *log, ngx_err_t err,
    const char *fmt, ...)
{

}


void 
dump_pool(ngx_pool_t* pool)
{
    while (pool)
    {
        printf("\tpool = 0x%x\n", pool);
        printf("\tpool->d.last = 0x%x\n", pool->d.last);
        printf("\tpool->d.end = 0x%x\n", pool->d.end);
        printf("\tpool->d.next = 0x%x\n", pool->d.next);
        printf("\tpool->d.failed = %d\n", pool->d.failed);
        printf("\tpool->max = %d\n", pool->max);
        printf("\tpool->current = 0x%x\n", pool->current);
        printf("\tpool->chain = 0x%x\n", pool->chain);
        printf("\tpool->large = 0x%x\n", pool->large);
        printf("\tpool->cleanup = 0x%x\n", pool->cleanup);
        printf("\tpool->log = 0x%x\n\n", pool->log);

        pool = pool->d.next;
    }

}


int 
main(int argc, char *argv[])
{
    ngx_uint_t   pool_size = 1024;
    ngx_pool_t  *pool;

    printf("\ncreate a new pool of %u bytes: \n", pool_size);
    pool = ngx_create_pool(pool_size, NULL);
    dump_pool(pool);

    ngx_destroy_pool(pool);

    return 0;
}

