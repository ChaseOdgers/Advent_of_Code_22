#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <mio/mmap.hpp>
// #include <mio/mio.hpp> if using single header
#include <algorithm>

int main()
{
    // NOTE: error handling omitted for brevity.
    const int fd = open("file.txt", O_RDONLY);
    mio::mmap_source mmap(fd, 0, mio::map_entire_file);
    // ...
}