#include <libavformat/avformat.h>

int main(int argc, char *argv[])
{
    int ret;
    
    ret = avpriv_io_move("111.txt","222.txt");
    if (ret <0){
        av_log(NULL,AV_LOG_ERROR,"Failed to rename\n");
    }
    av_log(NULL,AV_LOG_INFO,"Success to rename\n");

    ret = avpriv_io_delete("./mytestfile.txt");
    if (ret < 0)
    {
        av_log(NULL, AV_LOG_ERROR, "Failed to delete file\n");
        return -1;
    }
    av_log(NULL, AV_LOG_INFO, "Success to delete file\n");
    return 0;
}
