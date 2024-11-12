// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract ProductInventory {
    address public owner;
    mapping(uint => uint) public productStock;

    // Constructor marked as payable to allow receiving Ether on contract creation
    constructor() payable {
        owner = msg.sender;
    }

    // Modifier to restrict access to the owner only
    modifier onlyOwner() {
        require(msg.sender == owner, "Only the owner can perform this action.");
        _;
    }

    // Receive product to increase stock
    function receiveProduct(uint productId, uint quantity) public onlyOwner {
        productStock[productId] += quantity;
    }

    // Sale product to decrease stock
    function sellProduct(uint productId, uint quantity) public onlyOwner {
        require(productStock[productId] >= quantity, "Insufficient stock.");
        productStock[productId] -= quantity;
    }

    // Show stock for a specific product
    function showStock(uint productId) public view returns (uint) {
        return productStock[productId];
    }
}
