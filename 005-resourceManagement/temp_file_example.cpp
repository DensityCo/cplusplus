#include <cassert>
#include <cerrno>
#include <cstring>
#include <cstdio>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <unistd.h>


int tmp_file_c_style(const std::string& path, const std::string& initial_data)
{
    int fd = open("./tmpc", O_RDWR | O_CREAT);
    if(fd < 0)
    {
        perror("Opening tmpc");
        return -1;
    }

    ssize_t bytes_written = ::write(fd, initial_data.data(), initial_data.size());
    if(bytes_written < 0)
    {
        perror("writing initial data");
        return -1;
    }

    return fd;
}

/**
 * @brief use_c_file Create file, write data to it, close file, remove file.
 */
void use_c_file()
{
    std::string path("./tmpc");
    int fd = tmp_file_c_style(path.c_str(), "density ");

    std::string final_data("is awesome");

    size_t bytes_written = ::write(fd, final_data.data(), final_data.size());
    if(bytes_written < 0)
    {
        perror("writing final data");
        return;
    }

    close(fd);

    std::cerr << "Unlinking C file" << std::endl;
    unlink(path.c_str());
}


namespace
{
    /*Class invariant, file resource will be open for lifetime of the class.*/
    class tmp_file
    {
        std::string m_file_path;
        std::fstream m_file;

    public:
        tmp_file(const std::string& path, const std::string& initial_data)
            : m_file_path(path),
              m_file()
        {
            m_file.open(m_file_path, std::ios_base::out);
            if(!m_file) //Wait, how does that work?
            {
                //Never let an object finish construction if it's invariants cannot be held true.
                std::ostringstream msg;
                msg << "Error opening file: " << std::strerror(errno);
                throw std::runtime_error(msg.str());
            }

            write(initial_data);
        }

        void write(const std::string& data)
        {
            assert(m_file.good());

            m_file << data;
            m_file.flush();
        }

        ~tmp_file() noexcept
        {
            std::cerr << "Unlinking cpp file" << std::endl;
            (void)::unlink(m_file_path.c_str());
        }
    };
}

void use_cpp_file()
{
    std::string path("./tmpcpp");
    tmp_file my_file(path, "density ");

    my_file.write(" is awesome");
}

int main(int argc, char** argv)
{
    use_c_file();
    use_cpp_file();
}
