#include <stdexcept>

#include "gtest/gtest.h"
#include "string_list.h"

int main(int argc, char* argv[]) {
  std::srand(std::time(NULL));
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

class ArrayListStringTest : public ::testing::Test {
 protected:
  structures::ArrayListString default_list{};
  structures::ArrayListString list{10u};

  const char* content[10] = {"Smalltalk", "FORTRAN",    "Lisp",   "C",  "C++",
                             "Java",      "Javascript", "Python", "Go", "Lua"};

  void push_back_fill(const char* arr[]) {
    for (auto i = 0; i < list.max_size(); i++) {
      list.push_back(arr[i]);
    }
  }

  void push_front_fill(const char* arr[]) {
    for (auto i = 0; i < list.max_size(); i++) {
      list.push_front(arr[i]);
    }
  }
};

TEST_F(ArrayListStringTest, MaxSizeReturnCorrectValue) {
  ASSERT_EQ(default_list.max_size(), 10);
}

TEST_F(ArrayListStringTest, SizeReturnsCorrectValue) {
  list.push_back("BlaBlaBla");
  ASSERT_EQ(list.size(), 1);
}

TEST_F(ArrayListStringTest, ConstructorsSetsMaxSize) {
  ASSERT_EQ(default_list.max_size(), 10u);
  ASSERT_EQ(list.max_size(), 10u);
}

TEST_F(ArrayListStringTest, ConstructorsSetsSizeToMinusOne) {
  ASSERT_EQ(default_list.size(), 0);
  ASSERT_EQ(list.size(), 0);
}

TEST_F(ArrayListStringTest, ClearSetsSizeToMinusOne) {
  list.push_back("BlaBlaBla");
  ASSERT_EQ(list.size(), 1);
  list.clear();
  ASSERT_EQ(list.size(), 0);
}

TEST_F(ArrayListStringTest, PushBackIncreasesSize) {
  list.push_back("BlaBlaBla");
  ASSERT_EQ(list.size(), 1);
}

TEST_F(ArrayListStringTest, PushBackAddDataToEndOfList) {
  list.push_back("BlaBlaBla");
  list.push_back("BluBluBlu");
  ASSERT_STREQ(list[1], "BluBluBlu");
}

TEST_F(ArrayListStringTest, PushBackThrowsErrorWhenFull) {
  push_back_fill(content);
  ASSERT_EQ(list.size(), 10);
  ASSERT_THROW(list.push_back("oi"), std::out_of_range);
}

TEST_F(ArrayListStringTest, PushFrontIncreasesSize) {
  list.push_front("oi");
  ASSERT_EQ(list.size(), 1);
}

TEST_F(ArrayListStringTest, PushFrontInsertsDataInAtIndex0) {
  for (auto i = 0; i < list.max_size(); i++) {
    list.push_front(content[i]);
    ASSERT_STREQ(list[0], content[i]);
  }
}

TEST_F(ArrayListStringTest, PushFrontThrowsErrorWhenFull) {
  push_front_fill(content);
  ASSERT_THROW(list.push_front("oi"), std::out_of_range);
}

TEST_F(ArrayListStringTest, InsertIncreasesSize) {
  list.insert("oi", 0);
  ASSERT_EQ(list.size(), 1);
}

TEST_F(ArrayListStringTest, InsertThrowsErrorWhenFull) {
  push_back_fill(content);
  ASSERT_THROW(list.insert("oi", 1), std::out_of_range);
}

TEST_F(ArrayListStringTest, InsertThrowsErrorWhenInvalidIndex) {
  ASSERT_THROW(list.insert("oioioi", -1), std::out_of_range);
  ASSERT_THROW(list.insert("ououou", 1), std::out_of_range);
}

TEST_F(ArrayListStringTest, InsertsAtTheRightPlace) {
  for (auto i = 0; i < list.max_size() - 1; i++) {
    list.push_back(content[i]);
  }

  list.insert("oi", 5);
  ASSERT_EQ(list.size(), 10);
  ASSERT_STREQ(list[4], "C++");
  ASSERT_STREQ(list[5], "oi");
  ASSERT_STREQ(list[6], "Java");
}

TEST_F(ArrayListStringTest, InsertInOrderIncreasesSize) {
  for (auto i = 0; i < list.max_size(); i++) {
    list.insert_sorted("oi");
    ASSERT_EQ(i + 1, list.size());
  }
}

TEST_F(ArrayListStringTest, InsertInOrder) {
  const char* city[10] = {
      "Blumenau",       "Chapeco",   "Criciuma", "Florianopolis", "Itajai",
      "Jaragua_do_Sul", "Joinville", "Lages",    "Palhoca",       "Sao_Jose"};
  for (auto i = 9; i >= 0; --i) {
    list.insert_sorted(city[i]);
  }
  for (auto i = 0; i < 10; ++i) {
    ASSERT_STREQ(city[i], list[i]);
  }

  list.clear();

  list.insert_sorted("10");
  list.insert_sorted("-10");
  list.insert_sorted("42");
  list.insert_sorted("0");
  ASSERT_STREQ("-10", list[0]);
  ASSERT_STREQ("0", list[1]);
  ASSERT_STREQ("10", list[2]);
  ASSERT_STREQ("42", list[3]);
}

TEST_F(ArrayListStringTest, Empty) {
    ASSERT_TRUE(list.empty());
}

TEST_F(ArrayListStringTest, NotEmpty) {
    ASSERT_TRUE(list.empty());
    list.push_back("Sao_Jose");
    ASSERT_FALSE(list.empty());
}

TEST_F(ArrayListStringTest, Full) {
    const char *city[10] = {"Blumenau", "Chapeco", "Criciuma", \
    "Florianopolis", "Itajai", "Jaragua_do_Sul", "Joinville", \
    "Lages", "Palhoca", "Sao_Jose"};
    for (auto i = 0; i < 10; ++i) {
        list.push_back(city[i]);
    }
    ASSERT_EQ(10u, list.size());
}

TEST_F(ArrayListStringTest, PopThrowsErrorWhenEmpty) {
  ASSERT_THROW(list.pop(0), std::out_of_range);
}

TEST_F(ArrayListStringTest, PopThowsErrorWhenInvalidIndex) {
  push_back_fill(content);

  ASSERT_THROW(list.pop(-1), std::out_of_range);
  ASSERT_THROW(list.pop(10), std::out_of_range);
}

TEST_F(ArrayListStringTest, PopDecreasesSize) {
  push_back_fill(content);
  ASSERT_EQ(list.size(), 10);

  list.pop(5);
  ASSERT_EQ(list.size(), 9);
}

TEST_F(ArrayListStringTest, PopsTheCorrectElement) {
  push_back_fill(content);

  ASSERT_STREQ(list.pop(0), "Smalltalk");
  ASSERT_STREQ(list.pop(8), "Lua");
  ASSERT_STREQ(list.pop(0), "FORTRAN");
}

TEST_F(ArrayListStringTest, PopFrontThrowsErrorWhenEmpty) {
  ASSERT_THROW(list.pop_front(), std::out_of_range);
}

TEST_F(ArrayListStringTest, PopFrontDecreasesSize) {
  push_back_fill(content);
  ASSERT_EQ(list.size(), 10);

  list.pop_front();
  ASSERT_EQ(list.size(), 9);
}

TEST_F(ArrayListStringTest, PopFrontRemovesFrontElement) {
  push_back_fill(content);
  for (auto i = 0; i < list.max_size(); i++) {
    ASSERT_STREQ(list.pop_front(), content[i]);
  }
}

TEST_F(ArrayListStringTest, FindThrowsErrorWhenEmpty) {
  ASSERT_THROW(list.find("oi"), std::out_of_range);
}

TEST_F(ArrayListStringTest, FindReturnsSizeWhenElementNotFound) {
  push_back_fill(content);

  ASSERT_EQ(list.find("Haskell"), list.size());
}

TEST_F(ArrayListStringTest, FindReturnsTheIndexOfData) {
  push_back_fill(content);

  ASSERT_EQ(list.find("Lua"), 9);
  ASSERT_EQ(list.find("Smalltalk"), 0);
}

TEST_F(ArrayListStringTest, RemoveThrowsErrorWhenEmpty) {
  ASSERT_THROW(list.remove("oi"), std::out_of_range);
}

TEST_F(ArrayListStringTest, RemoveThrowsErrorWhenInvalidArgument) {
  push_back_fill(content);

  ASSERT_THROW(list.remove("Haskell"), std::invalid_argument);
}

TEST_F(ArrayListStringTest, RemoveElementRemovesElement) {
  push_back_fill(content);

  list.remove("Java");
  ASSERT_EQ(list.size(), 9);
  ASSERT_EQ(list.find("Java"), list.size());
  list.remove("Python");
  ASSERT_EQ(list.size(), 8);
  ASSERT_EQ(list.find("Python"), list.size());
}

TEST_F(ArrayListStringTest, ContainsReturnsFalseWhenDoesntContainsData) {
  ASSERT_FALSE(list.contains("oi"));

  push_back_fill(content);

  ASSERT_FALSE(list.contains("oi"));
}

TEST_F(ArrayListStringTest, ContainsReturnsTrueWhenContainsData) {
  push_back_fill(content);

  ASSERT_TRUE(list.contains("Java"));
}
