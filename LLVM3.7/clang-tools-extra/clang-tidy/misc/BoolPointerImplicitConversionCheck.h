//===--- BoolPointerImplicitConversionCheck.h - clang-tidy ------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_MISC_BOOLPOINTERIMPLICITCONVERSIONCHECK_H
#define LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_MISC_BOOLPOINTERIMPLICITCONVERSIONCHECK_H

#include "../ClangTidy.h"

namespace clang {
namespace tidy {
namespace misc {

/// \brief Checks for conditions based on implicit conversion from a bool
/// pointer to bool e.g.
/// bool *p;
/// if (p) {
///   // Never used in a pointer-specific way.
/// }
class BoolPointerImplicitConversionCheck : public ClangTidyCheck {
public:
  BoolPointerImplicitConversionCheck(StringRef Name, ClangTidyContext *Context)
      : ClangTidyCheck(Name, Context) {}
  void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override;
};

} // namespace misc
} // namespace tidy
} // namespace clang

#endif // LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_MISC_BOOLPOINTERIMPLICITCONVERSIONCHECK_H

