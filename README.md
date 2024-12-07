# bound_and_clamp.c

![CI/CD Status Badge](https://github.com/mofosyne/bound_and_clamp.c/actions/workflows/ci.yml/badge.svg)

various macros and functions for validating and guarding signals in c (Bounds, Clamps, etc...)

## install

```sh
$ clib install mofosyne/bound_and_clamp.c
```

## usage

### bound.h

 * is_above_bound(value, max)
 * is_below_bound(value, min)
 * is_within_bound(value, min, max)
 * is_out_of_bound(value, min, max)

### clamp.h

* clamp_upper(value, max)
* clamp_lower(value, min)
* clamp_range(value, min, max)

## Expected Test Output

This is useful to get a sense of how this will work.

So Given:

* min = -2
* max = 2

### Clamped Value Macros Outputs
| i | clamp_upper | clamp_lower | clamp_range |
|:---:|:---:|:---:|:---:|
| -5 | -5 | -2 | -2 |
| -4 | -4 | -2 | -2 |
| -3 | -3 | -2 | -2 |
| -2 | -2 | -2 | -2 |
| -1 | -1 | -1 | -1 |
|  0 |  0 |  0 |  0 |
|  1 |  1 |  1 |  1 |
|  2 |  2 |  2 |  2 |
|  3 |  2 |  3 |  2 |
|  4 |  2 |  4 |  2 |
|  5 |  2 |  5 |  2 |

### Bounded Value Macros Outputs
| i | is_below_bound | is_above_bound | is_within_bound | is_out_of_bound |
|:---:|:---:|:---:|:---:|:---:|
| -5 | **true** | false | false | **true** |
| -4 | **true** | false | false | **true** |
| -3 | **true** | false | false | **true** |
| -2 | false | false | **true** | false |
| -1 | false | false | **true** | false |
|  0 | false | false | **true** | false |
|  1 | false | false | **true** | false |
|  2 | false | false | **true** | false |
|  3 | false | **true** | false | **true** |
|  4 | false | **true** | false | **true** |
|  5 | false | **true** | false | **true** |

## license

GNUv3
