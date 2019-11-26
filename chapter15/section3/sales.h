// exceptions and inheritance
#include <stdexcept>
#include <string>

class Sales {
  public:
    static const int MONTHS = 12;

  private:
    double gross[MONTHS];
    int year;

  public:
    class bad_index: public std::logic_error {
      private:
        int bi; // bad index value

      public:
        explicit bad_index(
          int ix,
          const std::string & s = "Index error in Sales object\n"
        );
        int bi_val() const { return bi; }
        virtual ~bad_index() throw() {}
    };
    explicit Sales(int yy = 0);
    Sales(int yy, const double * gr, int n);
    virtual ~Sales() {}
    int getYear() const { return year; }
    virtual double operator[](int i) const;
    virtual double & operator[](int i);
};

class LabeledSales: public Sales {
  private:
    std::string label;

  public:
    class nbad_index: public Sales::bad_index {
      public:
        nbad_index(
          const std::string & lb,
          int ix,
          const std::string & s = "Index error in LabeledSales object\n"
        );
        const std::string & label_val() const { return lbl; }
        virtual ~nbad_index() throw() {}

      private:
        std::string lbl;
    };
    explicit LabeledSales(const std::string & lb = "none", int yy = 0);
    LabeledSales(const std::string & lb, int yy, const double * gr, int n);
    virtual ~LabeledSales() {}
    const std::string & getLabel() const { return label; }
    virtual double operator[](int i) const;
    virtual double & operator[](int i);
};
