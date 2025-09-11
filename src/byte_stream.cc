#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) : capacity_( capacity ) {}

void Writer::push( string data )
{
  uint64_t available = capacity_ - buffer_.size();
  if(available >= data.size()) {
    buffer_ += data;
    bytes_pushed_ += data.size();
  }//when data is bigger than the available space: to hum available space ko hi fill karein gai, baaqi data loss 
  else {
    buffer_ += data.substr(0, available);
    bytes_pushed_ += available;
  }
}

void Writer::close()
{
  closed_ = true;
}

bool Writer::is_closed() const
{
  return closed_; 
}

uint64_t Writer::available_capacity() const
{
  return capacity_ - buffer_.size();
}

uint64_t Writer::bytes_pushed() const
{
  return bytes_pushed_;
}

string_view Reader::peek() const
{
  return buffer_;
}

void Reader::pop( uint64_t len )
{
  while(len > 0) {
    buffer_.erase(0, 1)
    bytes_popped_++;
    len--;
  }
}

bool Reader::is_finished() const
{
  return buffer_.size() == 0 && closed_; // Your code here.
}

uint64_t Reader::bytes_buffered() const
{
  return buffer_.size(); // Your code here.
}

uint64_t Reader::bytes_popped() const
{
  return bytes_popped_; // Your code here.
}
