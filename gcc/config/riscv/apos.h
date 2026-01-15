
#define GNU_USER_TARGET_CRTI "crti.o%s"
#define GNU_USER_TARGET_CRTN "crtn.o%s"

/* Supplies STARTFILE_SPEC that is based on the GNU version in gnu-user.h, but
   uses crt0 instead of crt1, and is simplified. */
#define APOS_TARGET_STARTFILE_SPEC \
  "%{shared:; \
     static:crt0.o%s; \
     static-pie:rcrt0.o%s; \
     " PIE_SPEC ":Scrt0.o%s; \
     :crt0.o%s} " \
   GNU_USER_TARGET_CRTI " \
   %{static:crtbeginT.o%s; \
     shared|static-pie|" PIE_SPEC ":crtbeginS.o%s; \
     :crtbegin.o%s} "
#undef  STARTFILE_SPEC
#define STARTFILE_SPEC APOS_TARGET_STARTFILE_SPEC

#define APOS_TARGET_ENDFILE_SPEC \
  "%{static:crtend.o%s; \
     shared|static-pie|" PIE_SPEC ":crtendS.o%s; \
     :crtend.o%s} " \
   GNU_USER_TARGET_CRTN
#undef  ENDFILE_SPEC
#define ENDFILE_SPEC APOS_TARGET_ENDFILE_SPEC
