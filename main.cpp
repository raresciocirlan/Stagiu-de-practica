#include <iostream>
//#include <stdio.h>      /* for printf() and fprintf() */
//#include <stdlib.h>
#include <fstream>


#include <dlt/dlt.h>

#define DLT_INT32(INT_VAR)(void)dlt_user_log_write_int32(&log_local,INT_VAR)

#define DLT_FLOAT32(FLOAT32_VAR)(void)dlt_user_log_write_float32(&log_local,FLOAT32_VAR)

#define DLT_BOOL(BOOL_VAR)(void)dlt_user_log_write_bool(&log_local,BOOL_VAR)

#define DLT_RAW(BUF, LEN)(void)dlt_user_log_write_raw(&log_local, BUF, LEN);


using namespace std;


DLT_DECLARE_CONTEXT(flst_example2);


int main()
{
    DLT_REGISTER_APP("FileTransfer", "Al doilea exemplu");
    DLT_REGISTER_CONTEXT(flst_example2, "FLST", "Second context");

    int file_size, id;
    srand(time(NULL));
    id = rand();
    char buff[10];
    ifstream file ("file.txt", std::ifstream::binary);
    file.seekg(0, ifstream::end);
    file_size = file.tellg();
    file.seekg(0);
    DLT_LOG(flst_example2, DLT_LOG_INFO, DLT_STRING("FLST"), DLT_INT(id),DLT_STRING("file.txt"), DLT_INT(file_size));
    while(file.eof() != true)
    {
        file.read(buff,10);
        DLT_LOG(flst_example2, DLT_LOG_INFO, DLT_STRING("FLDA"), DLT_INT(id), DLT_RAW(buff, 10));

    }

    file.close();

    DLT_UNREGISTER_CONTEXT(flst_example2);
    DLT_UNREGISTER_APP();

    return 0;
}
