#include "magick_initialization.h"
#include <magick/api.h>
#include <signal.h>

#if defined(linux)
struct sigaction actions[100];

void saveSigaction(int signo) {
    struct sigaction  oact;
    if (sigaction(signo, NULL, &oact) < 0) {
        return;
    }
    actions[signo] = oact;
}

void restoreSigactoin(int signo) {
    sigaction(signo, &actions[signo], NULL);
}

void saveSigactions() {
#if defined(SIGHUP)
  (void) saveSigaction(SIGHUP);
#endif

#if defined(SIGINT)
  (void) saveSigaction(SIGINT);
#endif

#if defined(SIGQUIT)
  (void) saveSigaction(SIGQUIT);
#endif

#if defined(SIGABRT)
  (void) saveSigaction(SIGABRT);
#endif

#if defined(SIGFPE)
  (void) saveSigaction(SIGFPE);
#endif

#if defined(SIGTERM)
  (void) saveSigaction(SIGTERM);
#endif

#if defined(SIGBUS)
  (void) saveSigaction(SIGBUS);
#endif

#if defined(SIGSEGV)
  (void) saveSigaction(SIGSEGV);
#endif

#if defined(SIGXCPU)
  (void) saveSigaction(SIGXCPU);
#endif

#if defined(SIGXFSZ)
  (void) saveSigaction(SIGXFSZ);
#endif
}

void restoreSigactions() {
#if defined(SIGHUP)
  (void) restoreSigactoin(SIGHUP);
#endif

#if defined(SIGINT)
  (void) restoreSigactoin(SIGINT);
#endif

#if defined(SIGQUIT)
  (void) restoreSigactoin(SIGQUIT);
#endif

#if defined(SIGABRT)
  (void) restoreSigactoin(SIGABRT);
#endif

#if defined(SIGFPE)
  (void) restoreSigactoin(SIGFPE);
#endif

#if defined(SIGTERM)
  (void) restoreSigactoin(SIGTERM);
#endif

#if defined(SIGBUS)
  (void) restoreSigactoin(SIGBUS);
#endif

#if defined(SIGSEGV)
  (void) restoreSigactoin(SIGSEGV);
#endif

#if defined(SIGXCPU)
  (void) restoreSigactoin(SIGXCPU);
#endif

#if defined(SIGXFSZ)
  (void) restoreSigactoin(SIGXFSZ);
#endif
}

/*
 reserve sigactoins before InitializeMagick, and recover after.
 This step must be taken because signal masks and flags will be
 changed violating some rules described at:
 https://golang.org/pkg/os/signal/#hdr-Go_programs_that_use_cgo_or_SWIG
 in InitializeMagick, which will cause Go run-time panics not occur as expected.
*/
void init_magick() {
    saveSigactions();

    InitializeMagick(NULL);

    restoreSigactions();
}
#else
/*
  warning: sigacgion() cannot be safely used in macOS. It will cause Go runtime.sigtramp lost.
  See https://github.com/golang/go/issues/22805. This means Go run-time panics will not occur
  as expected, usually deadlock when panic.
*/
void init_magick() {
    InitializeMagick(NULL);
}
#endif
