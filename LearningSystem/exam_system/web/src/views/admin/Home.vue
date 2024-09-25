<script>
import tools from "@/utils/utils";
// import * as echarts from 'echarts';
// import axios from "axios";
export default {
  data() {
    return {
      currentDate: new Date(),
      lineData: [],
      pieData: [],
      userInfo: tools.getUserInfo(),
      searchForm: {},
      listData: [
        {
          name: "123",
        },
      ],
      tableLabel: {
        id: "ID",
        name: "网站名称",
        link: "网站链接",
      },
    };
  },
  created() {
    this.getPageList();
  },
  async mounted() {
    await this.fetchData();
    this.initLineChart();
    this.initPieChart();
  },
  methods: {
    // async fetchData() {
    //   try {
    //     const response = await axios.get('http/score');
    //     this.lineData = response.data.line; // 根据实际数据结构
    //     this.pieData = response.data.pie;   // 根据实际数据结构
    //   } catch (error) {
    //     console.error(error);
    //   }
    // },
  //   initLineChart() {
  //     const chart = echarts.init(this.$refs.lineChart);
  //     const option = {
  //       xAxis: {
  //         type: 'category',
  //         data: this.lineData.map(item => item.date) // 示例
  //       },
  //       yAxis: {
  //         type: 'value'
  //       },
  //       series: [{
  //         data: this.lineData.map(item => item.value), // 示例
  //         type: 'line'
  //       }]
  //     };
  //     chart.setOption(option);
  //   },
  //   initPieChart() {
  //     const chart = echarts.init(this.$refs.pieChart);
  //     const option = {
  //       series: [{
  //         type: 'pie',
  //         data: this.pieData.map(item => ({ name: item.name, value: item.value })) // 示例
  //       }]
  //     };
  //     chart.setOption(option);
  //   }
  // },

    //获取分页数据 定义方法
    getPageList() {
      //分页条件 查询条件
      let data = Object.assign(this.searchForm, this.pageInfo);
      this.$axios
        .get("/link/page", {
          params: data,
        })
        .then((res) => {
          //获取列表数据
          this.listData = res.data.list;
          //获取分页数据
          this.total = res.data.total;
        });
    }
  },
}
</script>

<template>
  <el-row class="home" :gutter="20">
    <el-col :span="8" style="margin-top: 20px">
      <!-- 第一张卡片 -->
      <el-card>
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
        <el-table :data="listData">
          <!-- prop传值 label转标签 -->
          <el-table-column
            v-for="(val, key) in tableLabel"
            :key="key"
            :prop="key"
            :label="val"
          >
          </el-table-column>
        </el-table>
      </el-card>
    </el-col>

    <el-col :span="16" style="margin-top: 20px">
      <div class="num">
        <el-card
          :body-style="{ display: 'flex', padding: 0 }"
          v-for="item in countData"
          :key="item.name"
          ><component
            :is="item.icon"
            class="icons"
            :style="{ background: item.color }"
          ></component>
          <div class="details">
            <p class="num">￥{{ item.value }}</p>
            <p class="txt">￥{{ item.name }}</p>
          </div>
        </el-card>
      </div>

      <!-- 图表 -->
      <div ref="lineChart" style="height: 300px;"></div>
      <div ref="pieChart" style="height: 300px;"></div>

    </el-col>
  </el-row>
</template>

<style scoped>
.home {
  height: 100%;
  overflow: hidden;
  .user {
    display: flex;
    align-items: center;
    border-bottom: 1px solid #ccc;
    margin-bottom: 20px;
    img {
      width: 250px;
      height: 250px;
      border-radius: 50%;
      margin-right: 40px;
      object-fit: cover; /* 确保图片覆盖整个容器，可能会裁剪图片的某些部分 */
    }
    .user-info {
      p {
        line-height: 40px;
      }
      .user-info-p {
        color: #999;
      }
      .user-info-fp {
        font-size: 40px;
      }
    }
  }
  .login-info {
    p {
      line-height: 30px;
      font-size: 14px;
      color: #999;
      span {
        color: #666;
        margin-left: 60px;
      }
    }
    .time {
      font-size: 13px;
      color: #999;
    }
  }
  .user-table {
    margin-top: 20px;
  }
  .num {
    display: flex;
    flex-wrap: wrap;
    justify-content: space-between;
    .el-card {
      width: 32%;
      margin-bottom: 20px;
    }
    .icons {
      width: 80px;
      height: 100px;
      font-size: 30px;
      text-align: center;
      line-height: 80px;
      color: #fff;
    }
    .details {
      margin-left: 15px;
      display: flex;
      /* flex-direction: column; //纵向排列 */
      justify-content: center;
    }
    .num {
      font-size: 30px;
      margin-bottom: 10px;
    }
    .txt {
      font-size: 15px;
      text-align: center;
      color: #999;
    }
  }
  .graph {
    margin-top: 20px;
    display: flex;
    justify-content: space-between;
    .el-card {
      width: 48%;
      height: 260px;
    }
  }
}
</style>
