#ifndef HTTP_MEDIA_STREAM
#define HTTP_MEDIA_STREAM

#include <Arduino.h>
#include "../http/HTTPClient_TE.h"

#include "MediaStream.h"

class HTTPMediaStream : public MediaStream
{
  public:
    HTTPMediaStream();
    bool open(String url) override;
    void close() override;
    int available() override;
    int read() override;
    int peek() override;
    void flush() override;

    int totalSize() override;

  private:
    int _chunkSize;
    int _chunkIndex;
    int _totalSize;
    HTTPClient_TE _httpClient;
    WiFiClient* _httpStream;

    void _readChunkSize();
};

#endif
