#ifndef INTF_TEST__TEST_H
#define INTF_TEST__TEST_H

#include "exception/exception.h"

namespace test {

class error_t
    : public std::logic_error
{
public:
    explicit error_t(const std::string& message)
        : std::logic_error(message.c_str())
    {}
    explicit error_t(const char *message)
        : std::logic_error(message)
    {}
};

}; // namespace test

#define ASSERT_FALSE(           V, T)        if(  V )                  THROW( test::error_t,                   << "ASSERT_FALSE failed: ['" << #V << "'] => ['" << (V) << "']" T )
#define EXPECT_FALSE(OS, COUNT, V, T)        if(  V )                  do { ++COUNT; OS << FILE_LINE(continue) << "EXPECT_FALSE failed: ['" << #V << "'] => ['" << (V) << "']" T << std::endl; } while(false)
#define ASSERT_TRUE(            V, T)        if(!(V))                  THROW( test::error_t,                   << "ASSERT_TRUE failed: ['" << #V << "'] => ['" << (V) << "']" T )
#define EXPECT_TRUE( OS, COUNT, V, T)        if(!(V))                  do { ++COUNT; OS << FILE_LINE(continue) << "EXPECT_TRUE failed: ['" << #V << "'] => ['" << (V) << "']" T << std::endl; } while(false)
#define ASSERT_COMP(            LHS, REL, RHS, T) if(!((LHS)REL(RHS))) THROW( test::error_t,                   << "ASSERT_COMP failed: ['" << #LHS << "' " << #REL <<" '" << #RHS << "'] => ['" << (LHS) << "' " << #REL <<" '" << (RHS) << "']" T)
#define EXPECT_COMP( OS, COUNT, LHS, REL, RHS, T) if(!((LHS)REL(RHS))) do { ++COUNT; OS << FILE_LINE(continue) << "EXPECT_COMP failed: ['" << #LHS << "' " << #REL <<" '" << #RHS << "'] => ['" << (LHS) << "' " << #REL <<" '" << (RHS) << "']" T << std::endl; } while(false)
#define TEST_TRY do { try
#define ASSERT_CATCH(           E, T) catch(E&) { break; } catch(...){ THROW( test::error_t,                   << "ASSERT_CATCH failed: Expected '" << #E << "', but received other exception." T);               break; }   \
                                                                       THROW( test::error_t,                   << "ASSERT_CATCH failed: Expected '" << #E << "', but received no exception." T); }                while(false)
#define EXPECT_CATCH(OS, COUNT, E, T) catch(E&) { break; } catch(...){      ++COUNT; OS << FILE_LINE(continue) << "ASSERT_CATCH failed: Expected '" << #E << "', but received other exception." T << std::endl;   break; }   \
                                                                            ++COUNT; OS << FILE_LINE(continue) << "EXPECT_CATCH failed: Expected '" << #E << "', but received no exception." T    << std::endl; } while(false)
#define ASSERT_STUB_IS_NOT_EMPTY                                       THROW( test::error_t,                   << "ASSERT_STUB_IS_NOT_EMPTY" )
#define EXPECT_EMPTY_STUB(OS, COUNT)                                   do { ++COUNT; OS << FILE_LINE(continue) << "EXPECT_EMPTY_STUB" << std::endl; } while(false)

#endif // INTF_TEST__TEST_H