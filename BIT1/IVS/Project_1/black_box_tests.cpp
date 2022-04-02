//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Red-Black Tree - public interface tests
//
// $NoKeywords: $ivs_project_1 $black_box_tests.cpp
// $Author:     Mikhail Diachenko <xdiach00@stud.fit.vutbr.cz>
// $Date:       $2022-03-04
//============================================================================//
/**
 * @file black_box_tests.cpp
 * @author Mikhail Diachenko
 * 
 * @brief Implementace testu binarniho stromu.
 */

#include <vector>

#include "gtest/gtest.h"

#include "red_black_tree.h"


int nodesCount = 9,
    nodeRoot = 3,
    nodeList[9] = {3, 7, 1, 11, 5, 9, 0, 2, 12},
    cntNodesLeaf = 10;


class EmptyTree:public::testing::Test
{      
    protected:

        BinaryTree tree = BinaryTree();
};


class NonEmptyTree:public::testing::Test
{
    protected:

        BinaryTree tree = BinaryTree();

        /**
         * @brief Construct a new Tree with following elements:
         * {3, 7, 1, 11, 5, 9, 0, 2, 12}
         */
        NonEmptyTree()
        {
            for (int val : nodeList) {
                tree.InsertNode(val);
            }
        }
};


class TreeAxioms:public::testing::Test
{
    protected:

        BinaryTree tree = BinaryTree();

        /**
         * @brief Construct a new Tree with following elements:
         * {3, 7, 1, 11, 5, 9, 0, 2, 12}
         */
        TreeAxioms()
        {
            for (int val : nodeList) {
                tree.InsertNode(val);
            }
        }
};


TEST_F(EmptyTree, InsertNode)
{    
    // insertion of node with value 3
    std::pair<bool, BinaryTree::Node_t *> pairFirst = tree.InsertNode(3);
    BinaryTree::Node_t *nodeFirst = pairFirst.second;
    ASSERT_TRUE(nodeFirst != NULL); 
    EXPECT_TRUE(pairFirst.first);

    EXPECT_EQ(nodeFirst->key, 3);
    EXPECT_EQ(nodeFirst->color, BinaryTree::BLACK);

    EXPECT_FALSE(nodeFirst->pLeft == NULL);
    EXPECT_FALSE(nodeFirst->pRight == NULL);

    EXPECT_TRUE(nodeFirst->pParent == NULL);

    // insertion of node with value 7
    std::pair<bool, BinaryTree::Node_t *> pairSecond = tree.InsertNode(7);
    BinaryTree::Node_t *nodeSecond = pairSecond.second;
    ASSERT_TRUE(nodeSecond != NULL);
    EXPECT_TRUE(pairSecond.first);

    EXPECT_EQ(nodeSecond->key, 7);
    EXPECT_EQ(nodeSecond->color, BinaryTree::RED);

    EXPECT_FALSE(nodeSecond->pLeft == NULL);
    EXPECT_FALSE(nodeSecond->pRight == NULL);

    EXPECT_FALSE(nodeSecond->pParent == NULL);
    EXPECT_EQ(nodeSecond->pParent->key, 3);

    // insertion of node with value 1
    std::pair<bool, BinaryTree::Node_t *> pairThird = tree.InsertNode(1);
    BinaryTree::Node_t *nodeThird = pairThird.second;
    ASSERT_TRUE(nodeThird != NULL);
    EXPECT_TRUE(pairThird.first);

    EXPECT_EQ(nodeThird->key, 1);
    EXPECT_EQ(nodeThird->color, BinaryTree::RED);

    EXPECT_FALSE(nodeThird->pLeft == NULL);
    EXPECT_FALSE(nodeThird->pRight == NULL);

    EXPECT_FALSE(nodeThird->pParent == NULL);
    EXPECT_EQ(nodeThird->pParent->key, 3);
}

TEST_F(EmptyTree, DeleteNode)
{
    for (int val : nodeList) {
        EXPECT_FALSE(tree.DeleteNode(val));
    }

    EXPECT_FALSE(tree.DeleteNode(13));
}

TEST_F(EmptyTree, FindNode)
{
    for (int val : nodeList) {
        EXPECT_TRUE(tree.FindNode(val) == NULL);
    }

    EXPECT_TRUE(tree.FindNode(13) == NULL);
}

TEST_F(NonEmptyTree, InsertNode)
{
    // insertion of node with value 69
    std::pair<bool, BinaryTree::Node_t *> pairNew = tree.InsertNode(69);
    BinaryTree::Node_t *nodeNew = pairNew.second;
    ASSERT_TRUE(nodeNew != NULL);
    EXPECT_TRUE(pairNew.first);
    EXPECT_EQ(nodeNew->key, 69);
    EXPECT_EQ(nodeNew->color, BinaryTree::RED);

    ASSERT_TRUE(nodeNew->pLeft != NULL);
    ASSERT_TRUE(nodeNew->pLeft != NULL);
    EXPECT_EQ(nodeNew->pRight->color, BinaryTree::BLACK);
    EXPECT_EQ(nodeNew->pLeft->color, BinaryTree::BLACK);

    EXPECT_TRUE(nodeNew->pRight->pRight == NULL);
    EXPECT_TRUE(nodeNew->pLeft->pRight == NULL);
    EXPECT_TRUE(nodeNew->pRight->pLeft == NULL);
    EXPECT_TRUE(nodeNew->pLeft->pLeft == NULL);

    ASSERT_TRUE(nodeNew->pParent != NULL);
    EXPECT_EQ(nodeNew->pParent->key, 12);
    EXPECT_EQ(nodeNew->pParent->color, BinaryTree::BLACK);

    // insertion of existing node with value 7
    std::pair<bool, BinaryTree::Node_t *> pairExisting = tree.InsertNode(7);
    BinaryTree::Node_t *nodeExisting = pairExisting.second;
    ASSERT_TRUE(nodeExisting != NULL);
    EXPECT_FALSE(pairExisting.first);

    EXPECT_EQ(nodeExisting->key, 7);
    EXPECT_EQ(nodeExisting->color, BinaryTree::BLACK);

    ASSERT_TRUE(nodeExisting->pLeft != NULL);
    ASSERT_TRUE(nodeExisting->pLeft != NULL);
    EXPECT_EQ(nodeExisting->pLeft->key, 3);
    EXPECT_EQ(nodeExisting->pRight->key, 11);

    ASSERT_FALSE(nodeExisting->pParent != NULL);

    // insertion of node with negative value -7
    std::pair<bool, BinaryTree::Node_t *> pairNewNeg = tree.InsertNode(-7);
    BinaryTree::Node_t *nodeNewNeg = pairNewNeg.second;
    ASSERT_TRUE(nodeNewNeg != NULL);
    EXPECT_TRUE(pairNewNeg.first);

    EXPECT_EQ(nodeNewNeg->key, -7);
    EXPECT_EQ(nodeNewNeg->color, BinaryTree::RED);

    ASSERT_TRUE(nodeNewNeg->pLeft != NULL);
    ASSERT_TRUE(nodeNewNeg->pLeft != NULL);
    EXPECT_TRUE(nodeNewNeg->pRight->pRight == NULL);
    EXPECT_TRUE(nodeNewNeg->pLeft->pRight == NULL);
    EXPECT_TRUE(nodeNewNeg->pRight->pLeft == NULL);
    EXPECT_TRUE(nodeNewNeg->pLeft->pLeft == NULL);

    ASSERT_TRUE(nodeNewNeg->pParent != NULL);
    EXPECT_EQ(nodeNewNeg->pParent->key, 0);
    EXPECT_EQ(nodeNewNeg->pParent->color, BinaryTree::BLACK);
}

TEST_F(NonEmptyTree, DeleteNode)
{
    for (int val : nodeList) {
        EXPECT_TRUE(tree.DeleteNode(val));
    }

    EXPECT_FALSE(tree.DeleteNode(0));
    EXPECT_FALSE(tree.DeleteNode(-7));
    EXPECT_FALSE(tree.DeleteNode(11));
}

TEST_F(NonEmptyTree, FindNode)
{
    for (int val : nodeList) {
        EXPECT_TRUE(tree.FindNode(val));
    }
}

TEST_F(TreeAxioms, Axiom1)
{
    std::vector<BinaryTree::Node_t *> nodesLeaf;
	tree.GetLeafNodes(nodesLeaf);

    // checking the GetLeafNodes function
    EXPECT_EQ(nodesLeaf.size(), cntNodesLeaf);
 
    for (BinaryTree::Node_t *node : nodesLeaf) {
        EXPECT_EQ(node->color, BinaryTree::BLACK);
    }
}

TEST_F(TreeAxioms, Axiom2)
{
    std::vector<BinaryTree::Node_t *> nodesAll;
    tree.GetNonLeafNodes(nodesAll);

    // checking the GetNonLeafNodes function
    EXPECT_EQ(nodesAll.size(), nodesCount);

    for (BinaryTree::Node_t *node : nodesAll) {
        if (node->color == BinaryTree::RED) {
            EXPECT_EQ(node->pLeft->color, BinaryTree::BLACK);
            EXPECT_EQ(node->pRight->color, BinaryTree::BLACK);
        }
    }
}

TEST_F(TreeAxioms, Axiom3)
{
    BinaryTree::Node_t *nodeRootF;
    nodeRootF = tree.GetRoot();

    // checking the GetRoot function
    ASSERT_EQ(nodeRootF->key, nodeRoot);

    std::vector<BinaryTree::Node_t *> nodesLeaf;
	tree.GetLeafNodes(nodesLeaf);

    BinaryTree:: Node_t *nodeCurrent;

    int nodesBlackLastCnt = -1,
        nodesBlackCnt;
    
    for (BinaryTree:: Node_t *node : nodesLeaf) {
        nodesBlackCnt = 0;
        nodeCurrent = node;

        while (nodeCurrent != nodeRootF) {
            if (nodeCurrent->color == BinaryTree::BLACK) {
                nodesBlackCnt++;
            }
            nodeCurrent = nodeCurrent->pParent;
        }

        if (nodesBlackLastCnt != -1) {
            ASSERT_EQ(nodesBlackLastCnt, nodesBlackCnt);
        }

        nodesBlackLastCnt = nodesBlackCnt;
    }
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


/*** Konec souboru black_box_tests.cpp ***/
