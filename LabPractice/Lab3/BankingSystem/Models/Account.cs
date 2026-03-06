using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BankingSystem.Models
{
    abstract class Account
    {
        protected int accountId;
        protected string name;
        protected double balance;
        protected uint permissions;
        protected double[] transactions;
        protected int transactionCount;

        protected Account(int accountId, string name, uint permissions)
        {
            this.accountId = accountId;
            this.name = name;
            this.permissions = permissions;
            this.balance = 0;
            this.transactions = new double[100];
            this.transactionCount = 0;
        }
        public abstract void Deposit(double amount);
        public abstract void Withdraw(double amount);
        public abstract void SaveToFile();
        public abstract void LoadFromFile();

        protected void AddTransaction(double amount)
        {
            if (transactionCount < transactions.Length)
            {
                transactions[transactionCount++] = amount;
            }
        }

        public void ShowTransactions()
        {
            for (int i = 0; i < transactionCount; i++)
            {
                Console.WriteLine(transactions[i]);
            }
        }

        protected bool CanWithdraw()
        {
            return (permissions & 1) != 0;
        }

        protected bool CanDeposit()
        {
            return (permissions & 2) != 0;
        }
        public void ShowAccountInfo()
        {
            Console.WriteLine("Account ID: " + accountId);
            Console.WriteLine("Name: " + name);
            Console.WriteLine("Balance: " + balance);
            Console.WriteLine("VIP: " + ((permissions & 8) != 0));
        }
    }
}