#ifndef TH_RANDOM_INC
#define TH_RANDOM_INC

#include "THGeneral.h"

#define _MERSENNE_STATE_N 624
#define _MERSENNE_STATE_M 397
/* A THRandom contains all the state required for a single random number stream */
typedef struct THRandom {
  /* The initial seed. */
  unsigned long the_initial_seed;
  int left;  /* = 1; */
  int initf; /* = 0; */
  unsigned long *next;
  unsigned long state[_MERSENNE_STATE_N]; /* the array for the state vector  */
  /********************************/

  /* For normal distribution */
  double normal_x;
  double normal_y;
  double normal_rho;
  int normal_is_valid; /* = 0; */
} THRandom;

#define torch_Random "torch.Random"

/* Manipulate THRandom objects */
TH_API THRandom * THRandom_new();
TH_API THRandom * THRandom_copy(THRandom *self, THRandom *from);
TH_API void THRandom_free(THRandom *gen);

/* Initializes the random number generator with the current time (granularity: seconds) and returns the seed. */
TH_API unsigned long THRandom_seed(THRandom *_random);

/* Initializes the random number generator with the given long "the_seed_". */
TH_API void THRandom_manualSeed(THRandom *_random, unsigned long the_seed_);

/* Returns the starting seed used. */
TH_API unsigned long THRandom_initialSeed(THRandom *_random);

/* Generates a uniform 32 bits integer. */
TH_API unsigned long THRandom_random(THRandom *_random);

/* Generates a uniform random number on [0,1[. */
TH_API double THRandom_uniform(THRandom *_random, double a, double b);

/** Generates a random number from a normal distribution.
    (With mean #mean# and standard deviation #stdv >= 0#).
*/
TH_API double THRandom_normal(THRandom *_random, double mean, double stdv);

/** Generates a random number from an exponential distribution.
    The density is $p(x) = lambda * exp(-lambda * x)$, where
    lambda is a positive number.
*/
TH_API double THRandom_exponential(THRandom *_random, double lambda);

/** Returns a random number from a Cauchy distribution.
    The Cauchy density is $p(x) = sigma/(pi*(sigma^2 + (x-median)^2))$
*/
TH_API double THRandom_cauchy(THRandom *_random, double median, double sigma);

/** Generates a random number from a log-normal distribution.
    (#mean > 0# is the mean of the log-normal distribution
    and #stdv# is its standard deviation).
*/
TH_API double THRandom_logNormal(THRandom *_random, double mean, double stdv);

/** Generates a random number from a geometric distribution.
    It returns an integer #i#, where $p(i) = (1-p) * p^(i-1)$.
    p must satisfy $0 < p < 1$.
*/
TH_API int THRandom_geometric(THRandom *_random, double p);

/* Returns true with probability $p$ and false with probability $1-p$ (p > 0). */
TH_API int THRandom_bernoulli(THRandom *_random, double p);

/* returns the random number state */
TH_API void THRandom_getState(THRandom *_random, unsigned long *state, long *offset, long *_left);

/* sets the random number state */
TH_API void THRandom_setState(THRandom *_random, unsigned long *state, long offset, long _left);
#endif
