#ifndef TH_GENERIC_FILE
#define TH_GENERIC_FILE "generic/THTensorRandom.h"
#else

TH_API void THTensor_(random)(THTensor *self, THRandom *_random);
TH_API void THTensor_(geometric)(THTensor *self, THRandom *_random, double p);
TH_API void THTensor_(bernoulli)(THTensor *self, THRandom *_random, double p);

#if defined(TH_REAL_IS_FLOAT) || defined(TH_REAL_IS_DOUBLE)
TH_API void THTensor_(uniform)(THTensor *self, THRandom *_random, double a, double b);
TH_API void THTensor_(normal)(THTensor *self, THRandom *_random, double mean, double stdv);
TH_API void THTensor_(exponential)(THTensor *self, THRandom *_random, double lambda);
TH_API void THTensor_(cauchy)(THTensor *self, THRandom *_random, double median, double sigma);
TH_API void THTensor_(logNormal)(THTensor *self, THRandom *_random, double mean, double stdv);
TH_API void THTensor_(multinomial)(THLongTensor *self, THRandom *_random, THTensor *prob_dist, int n_sample, int with_replacement);
#endif

#if defined(TH_REAL_IS_BYTE)
TH_API void THTensor_(getRNGState)(THRandom *_random, THTensor *self);
TH_API void THTensor_(setRNGState)(THRandom *_random, THTensor *self);
#endif

#endif
