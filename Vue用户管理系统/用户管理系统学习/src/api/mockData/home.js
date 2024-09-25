// 虚拟数据准备
export default {
  getTableData: () => {
    return {
      code: 200,
      data: {
        tableData: [
          {
            name: "小米",
            todayBuy: 50,
            monthBuy: 2000,
            totalBuy: 30000,
          },
          {
            name: "美的",
            todayBuy: 400,
            monthBuy: 6000,
            totalBuy: 75000,
          },
          {
            name: "格力",
            todayBuy: 600,
            monthBuy: 4000,
            totalBuy: 65500,
          },
          {
            name: "华为",
            todayBuy: 100,
            monthBuy: 500,
            totalBuy: 44000,
          },
          {
            name: "vivo",
            todayBuy: 100,
            monthBuy: 2100,
            totalBuy: 53000,
          },
          {
            name: "三星",
            todayBuy: 400,
            monthBuy: 2030,
            totalBuy: 60000,
          },
        ],
      },
    };
  },
  getCountData: () => {
    return {
      code: 200,
      data: [
        {
          name: "今日支付账单",
          value: 1234,
          icon: "SuccessFilled",
          color: "#2ec7c9",
        },
        {
          name: "今日收藏账单",
          value: 490,
          icon: "StarFilled",
          color: "#ffb980",
        },
        {
          name: "今日未支付账单",
          value: 9720,
          icon: "GoodsFilled",
          color: "#5ab1ef",
        },
        {
          name: "本月支付账单",
          value: 75350,
          icon: "SuccessFilled",
          color: "#2ec7c9",
        },
        {
          name: "本月收藏账单",
          value: 5200,
          icon: "StarFilled",
          color: "#ffb980",
        },
        {
          name: "本月未支付账单",
          value: 15000,
          icon: "GoodsFilled",
          color: "#5ab1ef",
        },
      ],
    };
  },
  getChartData: () => {
    return {
      code: 200,
      data: {
        orderData: {
          date: [
            "2018-10-01",
            "2019-06-04",
            "2020-07-09",
            "2021-11-25",
            "2022-12-12",
            "2023-02-31",
            "2024-01-15",
          ],
          data: [
            {
              格力: 24892,
              三星: 15500,
              Iphone: 8210,
              vivo: 9745,
              华为: 32572,
              小米: 1425,
            },
            {
              格力: 4892,
              三星: 1000,
              Iphone: 8210,
              vivo: 2505,
              华为: 20002,
              小米: 8425,
            },
            {
              格力: 21092,
              三星: 35000,
              Iphone: 5970,
              vivo: 245,
              华为: 8572,
              小米: 8225,
            },
            {
              格力: 28882,
              三星: 18850,
              Iphone: 8710,
              vivo: 1745,
              华为: 2500,
              小米: 1225,
            },
            {
              格力: 9807,
              三星: 1205,
              Iphone: 7182,
              vivo: 15585,
              华为: 22897,
              小米: 31000,
            },
            {
              格力: 1597,
              三星: 755,
              Iphone: 7182,
              vivo: 5465,
              华为: 2597,
              小米: 24200,
            },
            {
              格力: 9597,
              三星: 5755,
              Iphone: 25182,
              vivo: 15585,
              华为: 22897,
              小米: 400,
            },
          ],
        },
        videoData: [
          { name: "小米", value: 8848 },
          { name: "VIVO", value: 8237 },
          { name: "Huwai", value: 3278 },
          { name: "Bench", value: 8242 },
          { name: "111", value: 7532 },
          { name: "小米", value: 9352 },
        ],
        userData: [
          { date: "周一", new: 5, active: 200 },
          { date: "周二", new: 10, active: 820 },
          { date: "周三", new: 17, active: 360 },
          { date: "周四", new: 71, active: 180 },
          { date: "周五", new: 24, active: 240 },
          { date: "周六", new: 52, active: 700 },
          { date: "周日", new: 33, active: 100 },
        ],
      },
    };
  },
};
