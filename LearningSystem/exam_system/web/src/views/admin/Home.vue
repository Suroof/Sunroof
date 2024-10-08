<script>
import tools from "@/utils/utils";
// import { Line } from 'chart.js';
// import { Pie } from 'chart.js';
// import axios from "axios";
import * as echarts from "echarts";

export default {
  data() {
    return {
      currentDate: new Date(),
      userInfo: tools.getUserInfo(),
      searchForm: {},
      listData: [{ name: "123" }],
      tableLabel: {
        id: "ID",
        name: "网站名称",
        link: "网站链接",
      },
      lineChartData: [],
      pieChartData: [],
      booksData: [],
      loading: true,
      errorMessage: "",
    };
  },
  created() {
    this.getPageList();
  },
  mounted() {
    this.fetchChartData();
    this.fetchBooksData();
  },
  computed: {
  formattedText() {
    return this.rawText.replace(/\n/g, '<br>');
  }
},
  methods: {
    //获取分页数据 定义方法
    getPageList() {
      //分页条件 查询条件

      let data = Object.assign(this.searchForm, this.pageInfo);
      this.$axios
        //发送GET请求
        .get("/link/page", {
          params: data,
        })
        //处理响应
        .then((res) => {
          //获取列表数据
          this.listData = res.data.list;
          //获取分页数据
          this.total = res.data.total;
        });
    },

    fetchBooksData() {
      this.$axios
        .get("/books/bookslist")
        .then((response) => {
          this.booksData = response.data;
          console.log("数据为", this.booksData);
        })
        .catch((error) => {
          console.error("获取失败辣！:", error); // 添加错误处理，以便在请求失败时能够知道
        });
    },

    fetchChartData() {
      this.$axios
        .get("/product/productlist")
        .then((response) => {
          this.lineChartData = response.data;
          console.log("折线图取到的数据：", this.lineChartData);
          this.pieChartData = response.data;
          console.log("饼状图取到的数据：", this.pieChartData);
          this.renderLineChart(); // 渲染折线图
          this.renderPieChart(); // 渲染饼状图
        })
        .catch((error) => {
          console.error("获取图表数据失败:", error);
        });
    },
    renderLineChart() {
      const lineChart = echarts.init(this.$refs.lineChart);
      const option = {
        title: {
          text: "折线图",
          textStyle: {
            color: "#d1c9c9", // 设置标题颜色为红色
            fontWeight: "bold", // 设置字体为粗体
            fontFamily: "sans-serif", // 设置字体族
            fontSize: 20, // 设置字体大小
          },
        },
        tooltip: {
          trigger: "axis",
        },
        xAxis: {
          type: "category",
          data: this.lineChartData.map((item) => item.name), // 数据中name 字段
          axisLabel: {
            color: "#fcfdfd", // 设置横坐标轴标签颜色
          },
        },
        yAxis: {
          type: "value",
          axisLabel: {
            color: "#e9e5e5", // 设置横坐标轴标签颜色
          },
        },
        series: [
          {
            name: "数据值",
            type: "line",
            data: this.lineChartData.map((item) => item.price), // 数据中price 字段
          },
        ],
      };
      lineChart.setOption(option);
    },
    renderPieChart() {
      const pieChart = echarts.init(this.$refs.pieChart);
      const option = {
        title: {
          text: "饼状图",
          subtext: "数据分布",
          left: "center",
          textStyle: {
            color: "#d1c9c9", // 设置标题颜色为红色
            fontWeight: "bold", // 设置字体为粗体
            fontFamily: "sans-serif", // 设置字体族
            fontSize: 20, // 设置字体大小
          },
        },
        tooltip: {
          trigger: "item",
        },
        series: [
          {
            name: "数据分布",
            type: "pie",
            radius: "50%",
            data: this.pieChartData.map((item) => ({
              value: item.price, // 数据中 price 字段
              name: item.name, // 数据中 name 字段
            })),
            emphasis: {
              itemStyle: {
                shadowBlur: 10,
                shadowOffsetX: 0,
                shadowColor: "rgba(0, 0, 0, 0.5)",
              },
            },
          },
        ],
      };
      pieChart.setOption(option);
    },
  },
};
</script>

<template>
  <div class="background-container">
    <el-row class="home" :gutter="20">
      <el-col :span="8" style="margin-top: 6px">
        <!-- 第一张卡片 -->
        <el-card class="pixie">
          <div class="user">
            <img :src="userInfo.img" class="user" />
            <div class="user-info">
              <p class="user-info-fp">Admin</p>
              <p class="user-info-p">超级管理员</p>
            </div>
          </div>
          <div class="login-info">
            <p>上次登录时间:<span> 2025.6.1</span></p>
            <p>上次登录地点:<span> 北京</span></p>
            <time class="time">{{ currentDate }}</time>
          </div>
        </el-card>

        <!-- 第二张卡片 -->
        <el-card shadow="hover" class="user-table">
          <el-table :data="listData" class="insideTable custom-table">
            <!-- prop传值 label转标签 -->
            <el-table-column
              v-for="(val, key) in tableLabel"
              :key="key"
              :prop="key"
              :label="val"
              class="custom-column"
            >
            </el-table-column>
          </el-table>
        </el-card>
      </el-col>

      <!--右上卡片-->
      <el-col :span="16" style="margin-top: 6px">
        <div class="num">
          <el-card
            :body-style="{ display: 'flex', padding: 0 }"
            v-for="item in booksData"
            :key="item.author"
            ><component
              :is="item.icon"
              class="icons"
              :style="{ background: item.color }"
            ></component>
            <div class="details">
              <p class="num" >{{ item.title }}</p>
              <p class="txt" >{{ item.author }}</p>
            </div>
          </el-card>
        </div>

        <!-- 图表 -->

        <div class="chart-container">
          <div ref="lineChart" class="lineChart"></div>
          <div ref="pieChart" class="pieChart"></div>
        </div>
      </el-col>
    </el-row>
  </div>
</template>

<style scoped>
.pixie {
  backdrop-filter: blur(2px) saturate(158%);
  -webkit-backdrop-filter: blur(2px) saturate(158%);
  background-color: rgba(255, 255, 255, 0.32);
  border-radius: 10px;
  border: 1px solid rgba(209, 213, 219, 0.3);
  box-shadow: 0 8px 20px 0 rgba(31, 38, 135, 0.37);
}
.home {
  height: 100%;
  overflow: hidden;

  .user {
    display: flex;
    align-items: center;
    border-bottom: 1px solid #ccc;
    margin-bottom: 20px;
    height: 180px;
    background: rgba(255, 255, 255, 0.25);
    box-shadow: 0 8px 32px 0 rgba(31, 38, 135, 0.37);
    backdrop-filter: blur(4px);
    -webkit-backdrop-filter: blur(4px);
    border-radius: 10px;
    border: 1px solid rgba(255, 255, 255, 0.18);
    .user-info-fp {
      font-size: 24px;
      font-weight: bold;
    }
    img {
      width: 140px;
      height: 140px;
      border: none;
      border-radius: 50%;
      margin-right: 40px;
      margin-left: 10px;
      object-fit: cover; /* 确保图片覆盖整个容器，可能会裁剪图片的某些部分 */
    }

    .user-info {
      p {
        line-height: 40px;
      }

      .user-info-p {
        color: #7b7777;
      }
      .user-info-fp {
        font-size: 40px;
        font-family: "Courier New", Courier, monospace;
      }
    }
  }

  .login-info {
    p {
      line-height: 30px;
      font-size: 14px;
      color: #d1c9c9;

      span {
        color: #d1c9c9;
        margin-left: 60px;
      }
    }

    .time {
      font-size: 13px;
      color: #d1c9c9;
    }
  }

  .user-table {
    margin-top: 20px;
    background: rgba(255, 255, 255, 0.25);
    box-shadow: 0 8px 32px 0 rgba(31, 38, 135, 0.37);
    backdrop-filter: blur(4px);
    -webkit-backdrop-filter: blur(4px);
    border-radius: 10px;
    border: 1px solid rgba(255, 255, 255, 0.18);
  }
  .custom-table {
    backdrop-filter: blur(2px) saturate(158%);
    -webkit-backdrop-filter: blur(2px) saturate(158%);
    background-color: rgba(255, 255, 255, 0.32);
    border-radius: 10px;
    border: 1px solid rgba(209, 213, 219, 0.3);
  }
  .custom-column {
    text-align: center;
    font-size: 14px;
    color: #666;
    backdrop-filter: blur(2px) saturate(158%);
    -webkit-backdrop-filter: blur(2px) saturate(158%);
    background-color: rgba(255, 255, 255, 0.32);
    border-radius: 10px;
    border: 1px solid rgba(209, 213, 219, 0.3);
  }

  .num {
    display: flex;
    flex-wrap: wrap;
    justify-content: space-between;

    .el-card {
      width: 32%;
      margin-bottom: 20px;
      backdrop-filter: blur(2px) saturate(158%);
      -webkit-backdrop-filter: blur(2px) saturate(158%);
      background-color: rgba(255, 255, 255, 0.32);
      border-radius: 10px;
      border: 1px solid rgba(209, 213, 219, 0.3);
    }

    .icons {
      width: 80px;
      height: 100px;
      font-size: 30px;
      text-align: center;
      line-height: 80px;
      color: #fff;
      border-radius: 8px; /* 圆角效果 */
      background-color: #007bff; /* 按钮背景颜色 */
      transition: background-color 0.3s; /* 增加背景颜色过渡效果 */

      &:hover {
        background-color: #0056b3; /* 悬停时的背景颜色 */
      }
    }

    .details {
      margin-left: 15px;
      display: flex;
      justify-content: center;

      .num {
        font-size: 30px;
        margin-bottom: 10px;
      }

      .txt {
        font-size: 15px;
        text-align: center;
        color: #ffffff;
        margin-top: 12px;
        margin-left: 50px;
      }
    }
  }

  .graph {
    margin-top: 20px;
    display: flex;
    justify-content: space-between;

    .el-card {
      width: 48%;
      height: 260px;
      border-radius: 8px; /* 圆角效果 */
      box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1); /* 增加阴影效果 */
    }
  }

  .chart-container {
    width: 100%; /* 使容器宽度为100% */
    max-width: 1000px; /* 调整最大宽度，减小整体容器的宽度 */
    margin: 0 auto; /* 水平居中 */
  }

  .lineChart {
    height: 260px;
    margin-bottom: 10px;
  }
  .pieChart {
    height: 300px;
    margin-bottom: 150px;
  }
}
</style>
