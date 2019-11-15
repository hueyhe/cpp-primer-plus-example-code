// a table tennis base class
#ifndef TABLETENN0_H_
#define TABLETENN0_H_

#include <string>

using std::string;

class TableTennisPlayer {
  private:
    string firstname;
    string lastname;
    bool hasTable;

  public:
    TableTennisPlayer(
      const string & fn = "none",
      const string & ln = "none",
      bool ht = false
    );
    void name() const;
    bool HasTable() const { return hasTable; }
    void resetTable(bool v) { hasTable = v; }
};

#endif
