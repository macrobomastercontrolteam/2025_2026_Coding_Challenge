/* lpf_step_demo_alpha.c */
#include <math.h>
#include <stdint.h>
#include <stdio.h>

typedef double real;


/* =======================================================================
 *  TASK: Implement a single-function EMA smoother with internal state.
 *
 *  Function signature:
 *      real low_pass_filter(real x, real alpha, int init);
 *
 *  Usage (call once per control-loop tick):
 *      y = low_pass_filter(x, alpha, init);
 *
 *  Parameters:
 *      x      : current input sample
 *      alpha  : smoothing factor in (0, 1]; smaller -> smoother/slower
 *                (alpha = 1.0 -> pass-through / no smoothing)
 *      init   : set to 1 to (re)initialize; seeds y = x and stores alpha
 *               (use 0 for normal updates)
 *
 *  Requirements:
 *    - Keep static internal state: initialized flag, last output y, last alpha.
 *    - Clamp alpha into (0, 1]; if alpha <= 0 or alpha > 1, set alpha = 1.0.
 *    - On first call OR when init == 1:
 *        * store alpha
 *        * y <- x   (seed output)
 *        * return y
 *    - Otherwise (normal update):
 *        * y <- (1 - alpha) * y + alpha * x
 *        * return y
 * ======================================================================= */

real low_pass_filter(real x, real alpha, int init)
{
    /* TODO: implement per the spec above */
}

/* ------------------------- Demo ------------------------- */
int main(void)
{
    const real alpha = 0.10;
    const int  L  = 64; //samples
    const int  STEP_AT = 10;
    const real STEP_LOW  = 0.0;
    const real STEP_HIGH = 5.0;

    for (int n = 0; n < L; ++n) {
        real x = (n < STEP_AT) ? STEP_LOW : STEP_HIGH;
        int init = (n == 0) ? 1 : 0; //initialize on first sample
        real y = low_pass_filter(x, alpha, init);
        printf("%3d  in=%7.3f  out=%.8f\n", n, x, y);
    }
    return 0;
}
