// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract BankAccount {
    address public owner;
    uint public balanceInWei;

    // Constructor marked as payable to allow receiving Ether on contract creation
    constructor() payable {
        owner = msg.sender;
        balanceInWei = msg.value; // The contract will accept initial Ether sent during deployment
    }

    // Deposit function to add funds to the account
    function deposit() public payable {
        balanceInWei += msg.value;
    }

    // Withdraw function to withdraw funds from the account
    function withdraw(uint amountInEther) public {
        uint amountInWei = amountInEther * 1 ether;
        require(msg.sender == owner, "Only the owner can withdraw.");
        require(amountInWei <= balanceInWei, "Insufficient balance.");
        balanceInWei -= amountInWei;
        payable(msg.sender).transfer(amountInWei);
    }

    // Show balance function
    function showBalance() public view returns (uint) {
        return balanceInWei / 1 ether; // Converts wei to ether for display
    }
}
