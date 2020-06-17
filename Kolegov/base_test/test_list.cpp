#include "list.h"
#include <gtest.h>


TEST(TList, can_create_list)
{
	ASSERT_NO_THROW(TList<int> list);	
}

TEST(TList, can_add_item)
{
	TList<int> list;
	ASSERT_NO_THROW(list.Add(2));
}

TEST(TList, can_get_item)
{
	TList<int> list;
	list.Add(2);

	auto a = list[0];
	EXPECT_EQ(a,2);
}

TEST(TList, can_insert_item)
{
	TList<int> list;
	list.Add(3);
	list.Add(1);
	ASSERT_NO_THROW(list.Insert(2,1));
}
TEST(TList, can_get_inserted_item)
{
	TList<int> list;
	list.Add(3);
	list.Add(1);
	list.Insert(2, 1);

	auto a = list[1];
	EXPECT_EQ(a, 2);
}

TEST(TList, can_get_all_items_for)
{
	TList<int> list;
	list.Add(1);
	list.Add(3);
	list.Insert(2, 1);

	int a[] = { 1, 2, 3 };
	int b[3];

	int i = 0;
	for (auto e : list)
	{
		b[i] = e;
		i++;
	}

	for(int i = 0; i < 3; i++)
		EXPECT_EQ(a[i], b[i]);
}

TEST(TList, throws_when_get_elemnt_with_negative_index)
{
	TList<int> list;
	list.Add(3);
	list.Add(1);

	ASSERT_ANY_THROW(list[-1]);
}

TEST(TList, throws_when_get_elemnt_with_too_large_index)
{
	TList<int> list;
	list.Add(3);
	list.Add(1);

	ASSERT_ANY_THROW(list[5]);
}

TEST(TList, copied_list_equal_to_source_one)
{
	TList<int> list;
	list.Add(3);
	list.Add(1);

	TList<int> arr = list;

	EXPECT_TRUE(arr == list);
}

TEST(TList, copied_list_has_its_own_memory)
{
	TList<int> list;
	list.Add(3);
	list.Add(1);

	TList<int> arr = list;
	arr[1] = 5;

	EXPECT_NE(arr[1], list[1]);
}

TEST(TList, can_assert_lists)
{
	TList<int> list;
	list.Add(3);
	list.Add(1);

	TList<int> arr;
	arr.Add(5);
	arr.Add(4);

	arr = list;

	EXPECT_TRUE(arr == list);
}





