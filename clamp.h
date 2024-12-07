#ifndef __CLAMP_H
#define __CLAMP_H
#ifdef __cplusplus
extern "C"
{
#endif
#define clamp_upper(value, max) ((value) < (max) ? (value) : (max))
#define clamp_lower(value, min) ((value) > (min) ? (value) : (min))
#define clamp_range(value, min, max) clamp_lower(min, clamp_upper(value, max))
#ifdef __cplusplus
}
#endif
#endif
