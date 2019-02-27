[@bs.module "randomColor"] [@bs.val] external randomColor: unit => string = "";

open Css;
module Styles = {
  let product_card = (size: int, color: string) =>
    style([
      display(flexBox),
      backgroundColor(ghostwhite),
      flexDirection(column),
      width(px(size)),
      height(px(size)),
      border(px(3), solid, hex(color)),
      margin(px(5)),
    ]);

  let product_title =
    style([
      fontSize(px(20)),
      textAlign(center),
      height(px(50)),
      marginBottom(px(50)),
    ]);

  let product_price = style([fontSize(px(15)), textAlign(center)]);
};

let component = ReasonReact.statelessComponent("ProductCard");

let make =
    (~product: Product.t, ~selectedCustomer: option(Customer.t), _children) => {
  ...component,
  render: _self => {
    <div className={Styles.product_card(150, randomColor())}>
      <div className=Styles.product_title>
        {ReasonReact.string(product.name)}
      </div>
      <div className=Styles.product_price>
        {ReasonReact.string(string_of_float(product.price) ++ " $")}
      </div>
    </div>;
  },
};
