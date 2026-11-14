#pragma once
#include <string>
#include <cstddef>
#include <cstdint>

#ifdef SMS_GX_HAVE_GLES
namespace gx { namespace gles {
void setActive(bool);
bool active();
void install(void* (*getProc)(const char*));
bool desktopEntry(const char* name);
std::string shaderSource(const std::string& source, unsigned type);
bool metricActive();
bool needsRebasedIndices();
bool geometryShaders();
void memoryBarrier(unsigned bits);
struct IndexRange {
    size_t offset;
    int base;
    unsigned originalBuffer = 0;
    bool rebased = false;
    IndexRange(size_t offset, int count, int base, unsigned buffer, const uint32_t* indices);
    ~IndexRange();
};
}}
#else
namespace gx { namespace gles {
inline void setActive(bool) {}
inline bool active() { return false; }
inline void install(void* (*)(const char*)) {}
inline bool desktopEntry(const char*) { return false; }
inline std::string shaderSource(const std::string& source, unsigned) { return source; }
inline bool metricActive() { return false; }
inline bool needsRebasedIndices() { return false; }
inline bool geometryShaders() { return true; }
inline void memoryBarrier(unsigned) {}
struct IndexRange {
    size_t offset;
    int base;
    unsigned originalBuffer = 0;
    bool rebased = false;
    IndexRange(size_t, int, int, unsigned, const uint32_t*) {}
};
}}
#endif