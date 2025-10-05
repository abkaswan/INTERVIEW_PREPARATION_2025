import { DeliveryOptions } from "../checkout/DeliveryOptions";
import { CartItemDetails } from "../checkout/CartItemDetails";
import { DeliveryDate } from "../checkout/DeliveryDate";
export function OrderSummary({ cart, deliveryOptions }) {
  return (
    <div className="order-summary">
      {deliveryOptions.length > 0 &&
        cart.map((cartItem) => {
          const selectedDeliveryOption = deliveryOptions.find(
            (deliveryOption) => {
              return deliveryOption.id === cartItem.deliveryOptionId;
            }
          );
          return (
            <div className="cart-item-container">
              <DeliveryDate selectedDeliveryOption={selectedDeliveryOption} />

              <div key={cartItem.productId} className="cart-item-details-grid">
                <CartItemDetails cartItem={cartItem} />

                <DeliveryOptions
                  deliveryOptions={deliveryOptions}
                  cartItem={cartItem}
                />
              </div>
            </div>
          );
        })}
    </div>
  );
}
