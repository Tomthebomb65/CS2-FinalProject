// ============================================================================
// Spaceship Systems Manager Tests
// Thomas Guthmann
// ============================================================================

#include <gtest/gtest.h>
#include <cstring>

#include "alerts.h"
#include "alerts_list.h"
#include "ship_systems.h"
#include "crew_members.h"
#include "bst.h"

// ============================================================================
// ALERT CLASS TESTS
// ============================================================================

TEST(AlertTest, DefaultConstructor) {
    Alert a;
    EXPECT_EQ(a.getId(), 0);
    EXPECT_STREQ(a.getMessage(), "");
    EXPECT_EQ(a.getSeverity(), 0);
}

TEST(AlertTest, ParameterizedConstructor) {
    Alert a(101, "Hull breach detected", 0.0, 5);

    EXPECT_EQ(a.getId(), 101);
    EXPECT_STREQ(a.getMessage(), "Hull breach detected");
    EXPECT_EQ(a.getSeverity(), 5);
}

TEST(AlertTest, SettersWorkCorrectly) {
    Alert a;
    a.setId(42);
    a.setMessage("Test");
    a.setSeverity(3);

    EXPECT_EQ(a.getId(), 42);
    EXPECT_STREQ(a.getMessage(), "Test");
    EXPECT_EQ(a.getSeverity(), 3);
}

TEST(AlertTest, LongMessageHandling) {
    Alert a(1, "This is a very long alert message for testing", 0.0, 4);
    EXPECT_STREQ(a.getMessage(), "This is a very long alert message for testing");
}

// ============================================================================
// LINKED LIST TESTS (Alerts)
// ============================================================================

class AlertListTest : public ::testing::Test {
protected:
    LinkedList* list;

    void SetUp() override {
        list = new LinkedList();
    }

    void TearDown() override {
        delete list;
    }
};

TEST_F(AlertListTest, DefaultConstructor) {
    EXPECT_EQ(list->getSize(), 0);
    EXPECT_EQ(list->getHead(), nullptr);
}

TEST_F(AlertListTest, InsertSingleAlert) {
    list->insert(Alert(1, "Test", 0.0, 1));

    EXPECT_EQ(list->getSize(), 1);
    EXPECT_NE(list->getHead(), nullptr);
    EXPECT_EQ(list->getHead()->data.getId(), 1);
}

TEST_F(AlertListTest, InsertMultipleAlerts) {
    list->insert(Alert(1, "A", 0.0, 1));
    list->insert(Alert(2, "B", 0.0, 2));
    list->insert(Alert(3, "C", 0.0, 3));

    EXPECT_EQ(list->getSize(), 3);
}

TEST_F(AlertListTest, SearchFindsCorrectAlert) {
    list->insert(Alert(10, "Alpha", 0.0, 2));
    list->insert(Alert(20, "Beta", 0.0, 3));

    Alert* found = list->search(20);
    ASSERT_NE(found, nullptr);
    EXPECT_STREQ(found->getMessage(), "Beta");
}

TEST_F(AlertListTest, SearchReturnsNullWhenNotFound) {
    list->insert(Alert(10, "Alpha", 0.0, 2));
    EXPECT_EQ(list->search(999), nullptr);
}

TEST_F(AlertListTest, DeleteNodeWorks) {
    list->insert(Alert(1, "A", 0.0, 1));
    list->insert(Alert(2, "B", 0.0, 2));

    EXPECT_TRUE(list->deleteNode(1));
    EXPECT_EQ(list->getSize(), 1);
    EXPECT_EQ(list->search(1), nullptr);
}

TEST_F(AlertListTest, DeleteNodeNotFound) {
    list->insert(Alert(1, "A", 0.0, 1));
    EXPECT_FALSE(list->deleteNode(999));
    EXPECT_EQ(list->getSize(), 1);
}

TEST_F(AlertListTest, DeleteLastRemainingNode) {
    list->insert(Alert(1, "A", 0.0, 1));
    EXPECT_TRUE(list->deleteNode(1));
    EXPECT_EQ(list->getSize(), 0);
    EXPECT_EQ(list->getHead(), nullptr);
}

// ============================================================================
// SYSTEM CLASS TESTS
// ============================================================================

TEST(SystemTest, BaseClassConstructor) {
    System s(10, "Life Support", "Online");

    EXPECT_EQ(s.getId(), 10);
    EXPECT_STREQ(s.getName(), "Life Support");
    EXPECT_STREQ(s.getStatus(), "Online");
}

TEST(SystemTest, BaseClassSetters) {
    System s;
    s.setId(5);
    s.setName("Engine");
    s.setStatus("Offline");

    EXPECT_EQ(s.getId(), 5);
    EXPECT_STREQ(s.getName(), "Engine");
    EXPECT_STREQ(s.getStatus(), "Offline");
}

TEST(SystemTest, DerivedLifeSupportConstructor) {
    LifeSupport ls(
        20, "Life Support", "Nominal",
        98.0, 22.5, 14.7, "Active"
    );

    EXPECT_EQ(ls.getOxygenLevel(), 98.0);
    EXPECT_EQ(ls.getTemperature(), 22.5);
    EXPECT_EQ(ls.getCabinPressure(), 14.7);
    EXPECT_STREQ(ls.getCo2Scrubbing(), "Active");
}

TEST(SystemTest, DerivedPowerConstructor) {
    Power p(
        30, "Reactor", "Stable",
        500.0, 200.0, 150.0
    );

    EXPECT_EQ(p.getEnergyProduction(), 500.0);
    EXPECT_EQ(p.getEnergyStorage(), 200.0);
    EXPECT_EQ(p.getPowerUsage(), 150.0);
}

// ============================================================================
// CREW MEMBER TESTS
// ============================================================================

TEST(CrewMemberTest, ParameterizedConstructor) {
    CrewMember c(1, "John Doe", "Engineer", 72, false);

    EXPECT_EQ(c.getId(), 1);
    EXPECT_STREQ(c.getName(), "John Doe");
    EXPECT_STREQ(c.getRole(), "Engineer");
    EXPECT_EQ(c.getHeartRate(), 72);
    EXPECT_FALSE(c.getIsSleeping());
}

TEST(CrewMemberTest, SettersWorkCorrectly) {
    CrewMember c;
    c.setId(2);
    c.setName("Alice");
    c.setRole("Pilot");
    c.setHeartRate(80);
    c.setIsSleeping(true);

    EXPECT_EQ(c.getId(), 2);
    EXPECT_STREQ(c.getName(), "Alice");
    EXPECT_STREQ(c.getRole(), "Pilot");
    EXPECT_EQ(c.getHeartRate(), 80);
    EXPECT_TRUE(c.getIsSleeping());
}

// ============================================================================
// BST TESTS
// ============================================================================

class BSTTest : public ::testing::Test {
protected:
    BST* tree;

    void SetUp() override {
        tree = new BST();
    }

    void TearDown() override {
        delete tree;
    }
};

TEST_F(BSTTest, InsertSingleSystem) {
    EXPECT_TRUE(tree->insert(new System(10, "Engine", "Online")));
    EXPECT_EQ(tree->getSize(), 1);
}

TEST_F(BSTTest, InsertMultipleSystems) {
    tree->insert(new System(10, "A", "OK"));
    tree->insert(new System(5, "B", "OK"));
    tree->insert(new System(20, "C", "OK"));

    EXPECT_EQ(tree->getSize(), 3);
}

TEST_F(BSTTest, PreventDuplicateInsert) {
    tree->insert(new System(10, "A", "OK"));
    EXPECT_FALSE(tree->insert(new System(10, "Duplicate", "Fail")));
}

TEST_F(BSTTest, SearchFindsCorrectNode) {
    tree->insert(new System(10, "A", "OK"));
    tree->insert(new System(20, "B", "OK"));

    System* found = tree->search(20);
    ASSERT_NE(found, nullptr);
    EXPECT_STREQ(found->getName(), "B");
}

TEST_F(BSTTest, SearchReturnsNullWhenNotFound) {
    EXPECT_EQ(tree->search(999), nullptr);
}

TEST_F(BSTTest, DeleteLeafNode) {
    tree->insert(new System(10, "A", "OK"));
    tree->insert(new System(5, "B", "OK"));

    EXPECT_TRUE(tree->deleteNode(5));
    EXPECT_EQ(tree->getSize(), 1);
}

TEST_F(BSTTest, DeleteNodeWithOneChild) {
    tree->insert(new System(10, "A", "OK"));
    tree->insert(new System(5, "B", "OK"));
    tree->insert(new System(2, "C", "OK"));

    EXPECT_TRUE(tree->deleteNode(5));
    EXPECT_EQ(tree->getSize(), 2);
}

TEST_F(BSTTest, DeleteNodeWithTwoChildren) {
    tree->insert(new System(10, "A", "OK"));
    tree->insert(new System(5, "B", "OK"));
    tree->insert(new System(15, "C", "OK"));
    tree->insert(new System(12, "D", "OK"));
    tree->insert(new System(18, "E", "OK"));

    EXPECT_TRUE(tree->deleteNode(15));
    EXPECT_EQ(tree->getSize(), 4);
}

TEST_F(BSTTest, DeleteRootNode) {
    tree->insert(new System(10, "Root", "OK"));
    tree->insert(new System(5, "Left", "OK"));
    tree->insert(new System(15, "Right", "OK"));

    EXPECT_TRUE(tree->deleteNode(10));
    EXPECT_EQ(tree->getSize(), 2);
}

// ============================================================================
// POLYMORPHISM TESTS
// ============================================================================

TEST(PolymorphismTest, DerivedStoredAsBasePointer) {
    System* s1 = new LifeSupport(1, "Life", "OK", 95, 22, 14, "Active");
    System* s2 = new Power(2, "Reactor", "Stable", 500, 200, 150);

    EXPECT_STREQ(s1->getStatus(), "OK");
    EXPECT_STREQ(s2->getName(), "Reactor");

    delete s1;
    delete s2;
}

TEST(PolymorphismTest, BSTHandlesDerivedTypes) {
    BST tree;

    tree.insert(new LifeSupport(1, "Life", "OK", 95, 22, 14, "Active"));
    tree.insert(new Power(2, "Reactor", "Stable", 500, 200, 150));

    EXPECT_NE(tree.search(1), nullptr);
    EXPECT_NE(tree.search(2), nullptr);
}