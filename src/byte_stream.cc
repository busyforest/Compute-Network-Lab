#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) : capacity_( capacity ), pushed_bytes_(0),popped_bytes_(0),
error_ (false), closed_ (false), content("") {}

bool Writer::is_closed() const
{
  // Your code here.
  return closed_;
}

void Writer::push( string data )
{
  // Your code here.
  if(has_error() || is_closed()){
    return;
  }
  uint64_t len = min(available_capacity(), data.length());
  content.append(data.substr(0, len));
  pushed_bytes_ += len;
  return;
}

void Writer::close()
{
  Writer::closed_ = true;
  // Your code here.
}

uint64_t Writer::available_capacity() const
{
  // Your code here.
  return capacity_ - pushed_bytes_ + popped_bytes_;
}

uint64_t Writer::bytes_pushed() const
{
  // Your code here.
  return pushed_bytes_;
}

bool Reader::is_finished() const
{
  // Your code here.
  return closed_ && content.length() == 0;
}

uint64_t Reader::bytes_popped() const
{
  // Your code here.
  return popped_bytes_;
}

string_view Reader::peek() const
{
  // Your code here.
  return this->content;
}

void Reader::pop( uint64_t len )
{
  // Your code here.
  if(pushed_bytes_ == 0){
    return;
  }
  uint64_t poplen = min(len, capacity_);
  content.erase(0, poplen);
  popped_bytes_ += poplen;
}

uint64_t Reader::bytes_buffered() const
{
  // Your code here.
  return content.length();
}
