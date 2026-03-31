void copy_fromdouble(void *dst, double const *src) {
    unsigned char* dest_ptr = static_cast<unsigned char*>(dst);
    const unsigned char* src_ptr = reinterpret_cast<const unsigned char*>(src);
    
    if (dest_ptr < src_ptr) {
        for (int i = 0; i < sizeof(double); ++i) {
            dest_ptr[i] = src_ptr[i];
        }
    } else if (dest_ptr > src_ptr) {
        for (int i = sizeof(double); i > 0; --i) {
            dest_ptr[i-1] = src_ptr[i-1];
        }
    }
}