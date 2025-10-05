import axios from "axios";
import { useEffect, useState } from "react";
import "./CheckoutPage.css";
import { CheckoutHeader } from "./CheckoutHeader";
import { OrderSummary } from "./OrderSummary";
import { PaymentSummary } from "./PaymentSummary";
export function CheckoutPage({ cart, loadCart }) {
  const [deliveryOptions, setDeliveryOptions] = useState([]); // empty array because delivery options is an array and it is easier to map over an empty array
  const [paymentSummary, setPaymentSummary] = useState(null); // null because payment summary is an object and it is easier to check if it is loaded or not

  useEffect(() => {
    const fetchCheckoutData = async () => {
      let response = await axios.get("/api/delivery-options?expand=estimatedDeliveryTime");
      setDeliveryOptions(response.data);

      response = await axios.get("api/payment-summary");
      setPaymentSummary(response.data);
    }
    fetchCheckoutData();
    
  }, [cart]);

  return (
    <>
      <title>Checkout</title>
      <link rel="icon" type="image/svg+xml" href="images/cart-favicon.png" />
      <CheckoutHeader cart={cart} />
      
      <div className="checkout-page">
        <div className="page-title">Review your order</div>

        <div className="checkout-grid">
          <OrderSummary cart={cart} deliveryOptions={deliveryOptions} loadCart={loadCart} />

          <PaymentSummary paymentSummary={paymentSummary} />
        </div>
      </div>
    </>
  );
}
