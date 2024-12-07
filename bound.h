#ifndef __BOUND_H
#define __BOUND_H
#ifdef __cplusplus
extern "C"
{
#endif
#define is_above_bound(value, max) ((value) > (max))
#define is_below_bound(value, min) ((value) < (min))
#define is_within_bound(value, min, max) ((value) >= (min) && (value) <= (max))
#define is_out_of_bound(value, min, max) ((value) < (min) || (value) > (max))
#ifdef __cplusplus
}
#endif
#endif

