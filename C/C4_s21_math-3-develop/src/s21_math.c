#include "s21_math.h"

#define POW_2(x): x * x

int s21_abs(int x) {
  if (x < 0) {
    x *= -1;
  }
  return x;
}

long double s21_fabs(double x) {
  if (x < 0) {
    x *= -1;
  }
  return x;
}

static inline double s21_normalize_radian(double x) {
  while (x > S21_PI || x < -S21_PI) {
    x += x > S21_PI ? -2 * S21_PI : 2 * S21_PI;
  }
  return x;
}

long double s21_sin(double x) {
  x = s21_normalize_radian(x);
  long double temp = x, y = x;
  long double i = 1.;
  while (s21_fabs(temp) > S21_EPS) {
    temp = -1 * temp * x * x / (2 * i * (2 * i + 1));
    i += 1.;
    y += temp;
  }
  return y;
}

long double s21_cos(double x) {
  x = s21_normalize_radian(x);
  return s21_sin((S21_PI / 2.0) - x);
}

long double s21_tan(double x) {
  x = s21_normalize_radian(x);
  return s21_sin(x) / s21_cos(x);
}

long double s21_asin(double x) {
  long double temp = x, y = x;
  long double i = 1;
  while (s21_fabs(temp) > S21_EPS) {
    if (x < -1 || x > 1) {
      y = S21_NAN;
      break;
    }
    if (x == 1 || x == -1) {
      y = S21_PI / 2 * x;
      break;
    }
    temp *= x * x * (2 * i - 1) * (2 * i - 1) / ((2 * i + 1) * 2 * i);
    i += 1;
    y += temp;
  }
  return y;
}

long double s21_acos(double x) {
  if (x <= 1 && x >= -1) {
    x = S21_PI / 2. - s21_asin(x);
  } else {
    x = S21_NAN;
  }
  return x;
}

static inline long double s21_approximate(double x) {
  long double precision = x;
  long double y = x;

  for (int i = 1; s21_fabs(precision) > S21_EPS; i++) {
    precision = -1 * precision * x * x * (2 * i - 1) / (2 * i + 1);
    y += precision;
  }
  return y;
}

long double s21_atan(double x) {
  long double y = 0;

  if (x > 1) {
    y = S21_PI / 2 - s21_approximate(1 / x);
  } else if (x < -1) {
    y = S21_N_PI / 2 - s21_approximate(1 / x);
  } else if (x == 1) {
    y = S21_PI / 4;
  } else if (x == -1) {
    y = S21_N_PI / 4;
  } else if (x == 0) {
    y = 0;
  } else if (x < 1 && x > -1) {
    y = s21_approximate(x);
  }
  return y;
}

long double s21_ceil(double num) {
  long double out = num;
  long long n = (long long)num;
  double whole = (double)n;
  if (num < LLONG_MAX && num > LLONG_MIN && num == num) {
    if (num > 0 && !EQUAL(num, whole)) {
      out = whole + (num > 0);
    } else if (num < 0) {
      out = whole;
    }
  }
  return out;
}

long double s21_floor(double num) {
  if (num >= LLONG_MAX || num <= LLONG_MIN || num != num) {
    return num;
  }
  long long n = (long long)num;
  double d = (double)n;
  if (EQUAL(d, num) || num >= 0)
    return d;
  else
    return d - 1;
}

long double s21_exp(double x) {
  long double temp = 1, y = 1;
  long double i = 1;
  int flag = 0;
  if (x < 0) {
    x *= -1;
    flag = 1;
  }
  while (s21_fabs(temp) > S21_EPS) {
    temp *= x / i;
    i++;
    y += temp;
    if (y > S21_MAX_double) {
      y = S21_INF;
      break;
    }
  }
  y = flag == 1 ? y > S21_MAX_double ? 0 : 1. / y : y;
  return y = y > S21_MAX_double ? S21_INF : y;
}

long double s21_fmod(double x, double divisor) {
  long double y = s21_fabs(x);
  divisor = s21_fabs(divisor);
  int i = 1;
  while (y > divisor) {
    y = s21_fabs(x) - divisor * i;
    i++;
  }
  return x < 0 ? -y : y;
}

long double s21_log(double n) {
  int a = 0, b;
  double c = 0, d, e, f = 0;
  if (n < 0)
    c = S21_NAN;
  else if (n == 0) {
    c = S21_N_INF;
  } else {
    for (; (d = n / S21_E) > 1; ++a, n = d)
      ;
    for (; (d = n * S21_E) < 1; --a, n = d)
      ;

    d = (double)1 / (n - 1);
    d = d + d + 1;
    e = d * d;
    c = 0;
    b = 1, f = 1;
    while (c + S21_EPS < c + (double)1 / (b * f)) {
      c += (double)1 / (b * f);
      b += 2, f *= e;
    }
    c *= 2 / d;
  }
  return (double)a + c;
}

long double s21_pow_binary(double base, double exp) {
  double y = 1.0;
  unsigned long long exp_buf = exp;
  while (exp_buf != 0) {
    if (exp_buf & 1) {  // Проверка на нечётность
      y *= base;
    }
    base *= base;
    exp_buf >>= 1;  // Целочисленное деление на 2
  }
  return y;
}

long double s21_pow_fraction(double base, double exp) {
  double y = 1;
  if (exp < 0) {
    exp = -exp;
    y = s21_exp(exp * s21_log(exp));
    if (s21_fmod(exp, 2) != 0) {
      y = -y;
    }
  } else {
    y = s21_exp(exp * s21_log(base));
  }

  return y;
}

long double s21_pow(double base, double exp) {
  double y = 1;
  int even = 0;
  int neg = 0;

  if (base == 1 || exp == 0)
    y = 1;
  else if (__builtin_isinf(exp)) {
    if (base < 0 && __builtin_isinf(base) == 0)
      y = 1;
    else if (exp < 0 && base != 0) {
      if (base > 0 && base < 1)
        y = S21_INF;
      else if (__builtin_isinf(base) == -1)
        y = S21_INF;
      else
        y = 0;
    } else if (exp > 0) {
      if (base > -1 && base < 1)
        y = 0;
      else if (base == 1)
        y = 1;
      else
        y = S21_INF;
    } else
      y = S21_INF;
  } else if (__builtin_isinf(base)) {
    if (base < 0) {
      if (exp > 0 && EQUAL(s21_fmod(exp, 2), 0.0))
        y = S21_INF;
      else if (exp > 0 && EQUAL(s21_fmod(exp, 2), 1.0))
        y = S21_N_INF;
    }
    if (exp < 0)
      y = 0;
    else
      y = S21_INF;
  } else if (__builtin_isnan(exp) || __builtin_isnan(base))
    y = S21_N_NAN;
  else if (base == 0)
    if (exp > 0 && EQUAL((int)exp, exp))
      y = 0;
    else
      y = S21_INF;
  else if (base < 0 && s21_fabs(exp) - (long int)s21_fabs(exp) > EPSILON)
    y = S21_N_NAN;
  else {
    if (base < 0.0) {
      neg = 1;
      base *= -1;
      if ((int)exp % 2 == 0) even = 1;
    }
    if ((base != 0.0) && (base != 1.0 || exp != 0.0)) {
      double exp_abs = s21_fabs(exp);

      unsigned long int exp_integer_part = (long int)exp_abs;
      double exp_fraction_part = exp_abs - exp_integer_part;

      y = s21_pow_fraction(base, exp_fraction_part) *
          s21_pow_binary(base, exp_integer_part);

      if (exp < 0.0) {
        y = 1.0 / y;
      }
    }
    if (neg && !even) {
      y *= -1;
    }
  }
  return y;
}

long double s21_sqrt(double x) {
  long double y = 4, temp = 0;
  while (s21_fabs(y - temp) > S21_EPS) {
    if (x < 0) {
      y = S21_N_NAN;
      break;
    }
    temp = y;
    y = (temp + x / temp) / 2;
  }
  return y;
}