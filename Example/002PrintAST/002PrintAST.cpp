#include <clang-c/CXString.h>
#include <clang-c/Index.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

// enum CXChildVisitResult visitor(CXCursor cursor, CXCursor parent, CXClientData data)
// {
//   CXSourceLocation location = clang_getCursorLocation(cursor);
//   if (!clang_Location_isFromMainFile(location)) return CXChildVisit_Continue;
//   CXString    cxspelling = clang_getCursorSpelling(cursor);
//   const char *spelling   = clang_getCString(cxspelling);
//   CXString    cxkind     = clang_getCursorKindSpelling(clang_getCursorKind(cursor));
//   const char *kind       = clang_getCString(cxkind);

//   // std::cout<<spelling<<kind<<"--"<<'\n';
//   // printf("Cursor spelling, kind: %s, %s\n", spelling, kind);
//   clang_disposeString(cxspelling);
//   clang_disposeString(cxkind);
//   return CXChildVisit_Recurse;
// }

CXCursor mycursor;

CXChildVisitResult visitor(CXCursor cursor, CXCursor /* parent */, CXClientData clientData)
{
  CXSourceLocation location = clang_getCursorLocation(cursor);
  if (clang_Location_isFromMainFile(location) == 0) return CXChildVisit_Continue;

  CXCursorKind cursorKind = clang_getCursorKind(cursor);
CXType typeinfo =clang_getCursorType(cursor);
  if (cursorKind == CXCursor_StructDecl) { mycursor = cursor; }

  unsigned int curLevel  = *(reinterpret_cast<unsigned int *>(clientData));
  unsigned int nextLevel = curLevel + 1;

  const char *a = clang_getCString(clang_getCursorKindSpelling(cursorKind));
  const char *b = clang_getCString(clang_getCursorSpelling(cursor));
  const char *c=clang_getCString( clang_getTypeSpelling(typeinfo));
  std::cout << std::string(curLevel, '-') << " " << a << " (" << b << ") "<<"<"<<c<<">\n";

  clang_visitChildren(cursor, visitor, &nextLevel);

  return CXChildVisit_Continue;
}

int main(int argc, char **argv)
{
  CXIndex idx = clang_createIndex(1, 1);
  // std::cout << "asdf";
  CXTranslationUnit tu = clang_createTranslationUnitFromSourceFile(idx, "002sample.cpp", 0, 0, 0, 0);

  // clang_visitChildren(
  //     clang_getTranslationUnitCursor(tu),
  //     [](CXCursor c, CXCursor parent, CXClientData client_data)
  //     {
  //       CXSourceLocation location = clang_getCursorLocation(c);
  //       if (clang_Location_isFromMainFile(location) == 0) return CXChildVisit_Continue;

  //       std::cout << "Cursor '" << clang_getCString(clang_getCursorSpelling(c)) << "' of kind '"
  //                 << clang_getCString(clang_getCursorKindSpelling(clang_getCursorKind(c))) << "'\n";
  //       return CXChildVisit_Recurse;
  //     },
  //     nullptr);
  unsigned int treeLevel = 0;
  clang_visitChildren(clang_getTranslationUnitCursor(tu), visitor, &treeLevel);


std::cout<<"-----------"<<'\n';
treeLevel=0;
  clang_visitChildren(mycursor, visitor, &treeLevel);



  return 0;
}
