#ifndef RANGE_H_INCLUDED
#define RANGE_H_INCLUDED

template<typename T, typename F>
class Range
{
public:
    F const* BeginByte;
    F const* EndByte;

    void MakeRange(T* arr, size_t n)
    {
        BeginByte = (F*)arr;
        EndByte = (F*)(arr+n);
    }
};

#endif // RANGE_H_INCLUDED
