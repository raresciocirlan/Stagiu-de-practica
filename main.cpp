#include <iostream>
#include <stdio.h>      /* for printf() and fprintf() */
#include <stdlib.h>      

#include <dlt/dlt.h>

#define DLT_INT32(INT_VAR)(void)dlt_user_log_write_int32(&log_local,INT_VAR)

#define DLT_FLOAT32(FLOAT32_VAR)(void)dlt_user_log_write_float32(&log_local,FLOAT32_VAR)

#define DLT_BOOL(BOOL_VAR)(void)dlt_user_log_write_bool(&log_local,BOOL_VAR)




DLT_DECLARE_CONTEXT(con_example1);


int main()
{
    DLT_REGISTER_APP("Exemplu", "Primul exemplu");
    DLT_REGISTER_CONTEXT(con_example1, "CON", "First context");

    int file_size;
    char buff[10];
    ifstream file ("file.txt", std::ifstream::binary);
    file.seekg(0, ifstream::end);
    file_size = file.tellg();
    file.seekg(0);
    while(file.eof() != true)
    {
        file.read(buff,10);
        DLT_LOG(con_example1, DLT_LOG_INFO, DLT_STRING("file.txt"), DLT_INT(file_size), DLT_INT32(10), DLT_ARG_RAW(buff));

    }

    file.close();

    return 0;

    DLT_UNREGISTER_CONTEXT(con_example1);
    DLT_UNREGISTER_APP();
}
