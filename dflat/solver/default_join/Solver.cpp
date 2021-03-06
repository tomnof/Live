/*{{{
Copyright 2012-2016, Bernhard Bliem, Marius Moldovan
WWW: <http://dbai.tuwien.ac.at/research/project/dflat/>.

This file is part of D-FLAT.

D-FLAT is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

D-FLAT is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with D-FLAT.  If not, see <http://www.gnu.org/licenses/>.
*/
//}}}
#include <algorithm>
#include <unistd.h>

#include "Solver.h"
//#include "../../Decomposition.h"
//#include "../../Application.h"
//#include "../../Printer.h"

namespace {

bool isJoinable(const ItemTreeNode& left, const ItemTreeNode& right)
{
	return left.getItems() == right.getItems() &&
		(left.getType() == ItemTreeNode::Type::UNDEFINED || right.getType() == ItemTreeNode::Type::UNDEFINED || left.getType() == right.getType());
}
/*
ItemTreePtr join(const ItemTreePtr& left, const ItemTreePtr& right, bool setLeavesToAccept, bool optimize)
{
	assert(left);
	assert(right);
	assert(left->getNode());
	assert(right->getNode());
	if(!isJoinable(*left->getNode(), *right->getNode()))
		return ItemTreePtr();

	ItemTreePtr result;

	// Join left and right
	ItemTreeNode::Items items = left->getNode()->getItems();
	ItemTreeNode::Items auxItems;
	// Unify auxiliary items
	const auto& auxL = left->getNode()->getAuxItems();
	const auto& auxR = right->getNode()->getAuxItems();
	std::set_union(auxL.begin(), auxL.end(), auxR.begin(), auxR.end(), std::inserter(auxItems, auxItems.end()));

	ItemTreeNode::ExtensionPointers extensionPointers = {{left->getNode(), right->getNode()}};
	const bool leaves = left->getChildren().empty() && right->getChildren().empty();
	ItemTreeNode::Type type = left->getNode()->getType();
	if(type == ItemTreeNode::Type::UNDEFINED) {
		type = right->getNode()->getType();
		if(setLeavesToAccept && leaves && type == ItemTreeNode::Type::UNDEFINED)
			type = ItemTreeNode::Type::ACCEPT;
	}
	// TODO: make sure we really dont care about this (cause we dont care about the answer)
//	result.reset(new ItemTree(ItemTree::Node(new ItemTreeNode(std::move(items), std::move(auxItems), std::move(extensionPointers), type))));

	// Set (initial) cost of this node
	if(optimize) {
		if(leaves) {
			result->getNode()->setCost(left->getNode()->getCost() - left->getNode()->getCurrentCost() + right->getNode()->getCost());
			assert(left->getNode()->getCurrentCost() == right->getNode()->getCurrentCost());
			result->getNode()->setCurrentCost(left->getNode()->getCurrentCost());
		} else {
			assert(left->getNode()->getCurrentCost() == right->getNode()->getCurrentCost());
			assert(left->getNode()->getCurrentCost() == 0);
			switch(type) {
				case ItemTreeNode::Type::OR:
					// Set cost to "infinity"
					result->getNode()->setCost(std::numeric_limits<decltype(result->getNode()->getCost())>::max());
					break;

				case ItemTreeNode::Type::AND:
					// Set cost to minus "infinity"
					result->getNode()->setCost(std::numeric_limits<decltype(result->getNode()->getCost())>::min());
					break;

				case ItemTreeNode::Type::UNDEFINED:
					break;

				default:
					assert(false);
					break;
			}
		}
	}

	// Set counters (only in leaves)
	if(leaves) {
		std::set<std::string> keys;
		for(const auto& counter : left->getNode()->getCounters())
			keys.insert(counter.first);
		for(const auto& counter : right->getNode()->getCounters())
			keys.insert(counter.first);
		for(const auto& key : keys) {
			result->getNode()->setCounter(key, left->getNode()->getCounter(key) - left->getNode()->getCurrentCounter(key) + right->getNode()->getCounter(key));
			assert(left->getNode()->getCurrentCounter(key) == right->getNode()->getCurrentCounter(key));
			result->getNode()->setCurrentCounter(key, left->getNode()->getCurrentCounter(key));
		}
	}

	// Join children recursively
	auto lit = left->getChildren().begin();
	auto rit = right->getChildren().begin();
	while(lit != left->getChildren().end() && rit != right->getChildren().end()) {
		ItemTreePtr childResult = join(*lit, *rit, setLeavesToAccept, optimize);
		if(childResult) {
			// lit and rit match
			// Remember position of rit. We will later advance rit until is doesn't match with lit anymore.
			auto mark = rit;
join_lit_with_all_matches:
			// Join lit will all partners starting at rit
			do {
				// Update cost
				if(optimize) {
					switch(type) {
						case ItemTreeNode::Type::OR:
							result->getNode()->setCost(std::min(result->getNode()->getCost(), childResult->getNode()->getCost()));
							break;

						case ItemTreeNode::Type::AND:
							result->getNode()->setCost(std::max(result->getNode()->getCost(), childResult->getNode()->getCost()));
							break;

						case ItemTreeNode::Type::UNDEFINED:
							break;

						default:
							assert(false);
							break;
					}
				}

				result->addChildAndMerge(std::move(childResult));
				++rit;
				if(rit == right->getChildren().end())
					break;
				childResult = join(*lit, *rit, setLeavesToAccept, optimize);
			} while(childResult);

			// lit and rit don't match anymore (or rit is past the end)
			// Advance lit. If it joins with mark, reset rit to mark.
			++lit;
			if(lit != left->getChildren().end()) {
				childResult = join(*lit, *mark, setLeavesToAccept, optimize);
				if(childResult) {
					rit = mark;
					goto join_lit_with_all_matches;
				}
			}
		}
		else {
			// lit and rit don't match
			// Advance iterator pointing to smaller value
			if((*lit)->getNode()->getItems() < (*rit)->getNode()->getItems())
				++lit;
			else
				++rit;
		}
	}

	// In leaves, make sure two branches can only be joined if they have the same length
	assert(result);
	if(result->getChildren().empty() && (!left->getChildren().empty() || !right->getChildren().empty()))
		result.reset();

	return result;
}
*/
} // anonymous namespace

namespace solver { namespace default_join {

//Solver::Solver(const Decomposition& decomposition, const Application& app, bool setLeavesToAccept)
//Solver::Solver(const Decomposition& decomposition, bool setLeavesToAccept) : ::Solver(decomposition, app)
Solver::Solver(bool setLeavesToAccept) : setLeavesToAccept(setLeavesToAccept)
{
}

ItemTreePtr Solver::compute(DecompositionPtr decompositionPtr)
{
    // dummy compute - TODO: remove
    float sleepTime = 10000L+(long)((1e5-1e4)*rand()/(RAND_MAX+1.0));
    usleep(sleepTime);
    return nullptr;
}
/*
{
//	const auto nodeStackElement = app.getPrinter().visitNode(decomposition);

//	assert(decomposition.getChildren().size() > 1);
	// Compute item trees of child nodes
	// When at least two have been computed, join them with the result so far
	// TODO Use a balanced join tree (with smaller "tables" further down)
	auto it = decompositionPtr->getChildren().begin();
//	ItemTreePtr result = (*it)->getSolver().compute();
	ItemTreePtr result = compute(*it);
	for(++it; it != decompositionPtr->getChildren().end(); ++it) {
		if(!result)
			return ItemTreePtr();
//		ItemTreePtr itree = (*it)->getSolver().compute();
		ItemTreePtr itree = compute(*it);
		if(!itree)
			return ItemTreePtr();
//		result = join(result, itree, setLeavesToAccept, !app.isOptimizationDisabled());
		result = join(result, itree, setLeavesToAccept, true);
	}

//	if(result && result->finalize(app, decomposition.isRoot(), app.isPruningDisabled() == false || decomposition.isRoot()) == false)
//		result.reset();
//	app.getPrinter().solverInvocationResult(decomposition, result.get());
	return result;
}
*/
}} // namespace solver::default_join
