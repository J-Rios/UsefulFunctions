/*************************************************************************/
/* In C#, known as null-conditional operator (?), It is used to test for */
/* null before performing a member access (?.) or index (?[) operation.  */
/*                                                                       */
/* These operators help you write less code to handle null checks,       */
/* especially for descending into data structures.                       */
/*************************************************************************/

// Case of uses (data_type? mean a variable that allow accept null value)
  int? length = customers?.Length; // Null if customers is null, else get the length
  Customer? first = customers?[0]; // Null if customers is null, else get the customer
  int? count = customers?[0]?.Orders?.Count(); // Null if customers, the first customer, or Orders is null

/*************************************************************************/

// Example of safe way to invoking delegates in a thread
  PropertyChanged?.Invoke(e);

// The old way was
  var handler = this.PropertyChanged;
  if (handler != null)
      handler(…)
