#include <libavutil/log.h>
#include <libavformat/avformat.h>

int main(int argc, char const *argv[])
{
    int ret;
    AVFormatContext *fmt_ctx = NULL;

    av_log_set_level(AV_LOG_INFO);

    // 注册多媒体格式协议
    av_register_all();

    ret = avformat_open_input(&fmt_ctx, "./test.mp4", NULL, NULL);

    if (ret < 0)
    {
        av_log(NULL, AV_LOG_ERROR, "Can't open file: %s\n", av_err2str(ret));
        return -1;
    }

    // 打印相关 metadata 信息
    av_dump_format(fmt_ctx, 0, "./test.mp4", 0);

    avformat_close_input(&fmt_ctx);

    return 0;
}
